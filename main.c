#include <stdio.h>
#include "type/type.h"
#include "constant/constant.h"
#include "cal/cal.h"

static int a = 10;

int main() {
    printf("Hello, World!你好\n");
    printf("----------------------\n");
    //type_print();
    //const_print_define();
    //const_print_const();
    //const_print_val();
    //const_print_store(a);
    printf("----------------------\n");

    // cal_base_result();
    cal_base_result01();
    printf("----------------------\n");
    return 0;
}
