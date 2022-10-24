#include <stdio.h>
#include "type/type.h"
#include "constant/constant.h"

int main() {
    printf("Hello, World!\n");
    printf("----------------------\n");
    type_print();
    const_print();
    printf("----------------------\n");
    return 0;
}
