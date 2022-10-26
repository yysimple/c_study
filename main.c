#include <stdio.h>
#include "type/type.h"
#include "constant/constant.h"

int main() {
    printf("Hello, World!你好\n");
    printf("----------------------\n");
    type_print();
    const_print_define();
    const_print_const();
    const_print_val();
    printf("----------------------\n");
    return 0;
}
