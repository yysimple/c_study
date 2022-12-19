#pragma once
#include <netinet/in.h>
// 最大域名长度
#define MAX_NAME_LEN 255
#define DEFAULT_PORT "53"
#define MAX_LABEL_LEN 63
#define MAX_PACKET_LEN 512
#define DNS_HEADER_LEN 12

union sockaddr_t {
    struct in_addr a4;
    struct in6_addr a6;
};

// IP地址结构
struct ipaddr_t {
    int af;
    union sockaddr_t addr;
};

// 取DNS服务器，成功返为0
int dns_get_server(char *dnssvr, int n);

// 生成DNS请求包，成功返回0
int dns_pack_request(unsigned char *buf, int *size, const char *name);

// 解析DNS回应包，成功返回0，addrs和addrnum，外部须free(addrs)
int dns_parse_response(unsigned char *buf, int size, struct ipaddr_t **addrs, int *addrnum);