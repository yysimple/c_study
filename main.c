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

static int a = 10;

int main(int argc, char *argv[]) {
    printf("Hello, World!你好\n");
    printf("----------------------\n");
    //type_print();
    //const_print_define();
    //const_print_const();
    //const_print_val();
    //const_print_store(a);
    //printf("----------------------\n");

    // cal_base_result();
    //cal_base_result01();
    //condition_test();
    // enum_test();
    // enum_switch();
    // test_max_multi_nums();
    // test_no_point_max_multi_nums();
    // test_callback();
    //test_print_str();
    // use_struct();
    if (argc < 2) {
        printf("please input domain!\n");
        return -1;
    }
    dns_client_commit(argv[1]);
    printf("----------------------\n");
    //union_use();
    // cover_address_use();
    // test_file_write();
    // test_file_read();
    //const_define();
    //param_define();
    // test_file_err();
    // test_dividend_zero();
    return 0;
}
