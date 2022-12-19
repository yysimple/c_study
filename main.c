#include <stdio.h>
#include "type/type.h"
#include "constant/constant.h"
#include "cal/cal.h"
#include "enum/enum.h"
#include "point/point.h"
#include "str/str.h"
#include "struct/struct.h"
#include "file/file.h"
#include "predefine/pre.h"
#include "error/error.h"
#include "test/net/domian_analysis.h"
#include "test/util/dns_util.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>

static int a = 10;

// 日常学习的main方法
//int main(int argc, char *argv[]) {
//    printf("Hello, World!你好\n");
//    printf("----------------------\n");
//    //type_print();
//    //const_print_define();
//    //const_print_const();
//    //const_print_val();
//    //const_print_store(a);
//    //printf("----------------------\n");
//
//    // cal_base_result();
//    //cal_base_result01();
//    //condition_test();
//    // enum_test();
//    // enum_switch();
//    // test_max_multi_nums();
//    // test_no_point_max_multi_nums();
//    // test_callback();
//    //test_print_str();
//    // use_struct();
//    if (argc < 2) {
//        printf("please input domain!\n");
//        return -1;
//    }
//    dns_client_commit(argv[1]);
//    printf("----------------------\n");
//    //union_use();
//    // cover_address_use();
//    // test_file_write();
//    // test_file_read();
//    //const_define();
//    //param_define();
//    // test_file_err();
//    // test_dividend_zero();
//    return 0;
//}

char name[MAX_NAME_LEN];
char dns_server[MAX_NAME_LEN];
char port[6] = DEFAULT_PORT;
unsigned char buf[MAX_PACKET_LEN];

int udpSocket(const char *ip, const char *port, struct sockaddr *addr, socklen_t *addrlen) {
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    struct addrinfo *result;
    int s = getaddrinfo(ip, port, &hints, &result);
    if (s != 0) {
        errno = ENOSYS;
        return -1;
    }

    struct addrinfo *rp;
    int optval = 1;
    int sfd = 0;
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sfd >= 0)
            break;
        close(sfd);
    }
    freeaddrinfo(result);
    if (rp) {
        socklen_t len = rp->ai_addrlen > *addrlen ? *addrlen : rp->ai_addrlen;
        memcpy(addr, rp->ai_addr, len);
        *addrlen = len;
        return sfd;
    } else {
        return -1;
    }
}

int execute(int sfd, struct sockaddr_storage *sendaddr, socklen_t saddrlen) {
    // 生成请求包
    int sz = MAX_PACKET_LEN;
    if (dns_pack_request(buf, &sz, name)) {
        fprintf(stderr, "request error: %s\n", name);
        return 1;
    }
    // 发送
    if (sendto(sfd, buf, sz, 0, (const struct sockaddr *) sendaddr, saddrlen) != sz) {
        perror("sendto: ");
        return 1;
    }
    // 接收
    struct sockaddr_storage recvaddr;
    socklen_t raddrlen = sizeof(struct sockaddr_storage);
    sz = recvfrom(sfd, buf, MAX_PACKET_LEN, 0, (struct sockaddr *) &recvaddr, &raddrlen);
    if (sz == -1) {
        perror("recvfrom: ");
        return 1;
    }
    // 解析回应包
    struct ipaddr_t *addrs;
    int addrnum;
    int code = dns_parse_response(buf, sz, &addrs, &addrnum);
    if (code != 0) {
        switch (code) {
            case 1:
                fprintf(stderr, "Format error\n");
                return 1;
            case 2:
                fprintf(stderr, "Server failure\n");
                return 1;
            case 3:
                fprintf(stderr, "Name Error\n");
                return 1;
            case 4:
                fprintf(stderr, "Not Implemented\n");
                return 1;
            case 5:
                fprintf(stderr, "Refused\n");
                return 1;
            default:
                break;
        }
    }
    // 打包IP列表
    char sip[40];
    int i;
    for (i = 0; i < addrnum; ++i) {
        struct ipaddr_t *addr = &addrs[i];
        if (inet_ntop(addr->af, &addr->addr, sip, 40)) {
            printf("%s\n", sip);
        }
    }

    free(addrs);
    return 0;
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: test dns [dns server] [port] name\n");
        return 1;
    }
    // 取参数，一般第一个参数是执行文件名称，这里拿到最后一个参数 ./c_study nps.yysimple.tech
    strncpy(name, argv[argc - 1], MAX_NAME_LEN);
    if (argc > 2) {
        // 如果大于两个参数，则是自己指定dns服务器，可以跳过下面获取dns的操作，默认第二个参数
        strncpy(dns_server, argv[1], MAX_NAME_LEN);
        if (argc > 3)
            strncpy(port, argv[2], 6);
    } else {
        if (dns_get_server(dns_server, MAX_NAME_LEN)) {
            fprintf(stderr, "get dns server failed\n");
            return 1;
        }
    }
    // 建立连接
    struct sockaddr_storage sendaddr;
    socklen_t saddrlen = sizeof(struct sockaddr_storage);
    int sfd = udpSocket(dns_server, port, (struct sockaddr *) &sendaddr, &saddrlen);
    if (sfd < 0) {
        perror("udpSocket: ");
        return 1;
    }
    // 具体逻辑
    int ret = execute(sfd, &sendaddr, saddrlen);

    close(sfd);
    return ret;
}