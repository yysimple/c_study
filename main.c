#include <stdio.h>
#include "type/type.h"
#include "constant/constant.h"

int main() {
    printf("Hello, World!\n");
    printf("----------------------\n");
    type_print();
    const_print_define();
    const_print_const();
    printf("----------------------\n");
    return 0;
}
