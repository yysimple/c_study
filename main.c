#include <stdio.h>
#include "type/type.h"
#include "constant/constant.h"

static int a = 10;

int main() {
    printf("Hello, World!你好\n");
    printf("----------------------\n");
    type_print();
    const_print_define();
    const_print_const();
    const_print_val();
    const_print_store(a);
    printf("----------------------\n");
    return 0;
}
