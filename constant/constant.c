#include <stdio.h>
#include "constant.h"


#define LENGTH 10
#define WIDTH  5
#define NEWLINE '\n'

int const_print_define() {
    int area;
    area = LENGTH * WIDTH;
    printf("define value of area : %d", area);
    printf("%c", NEWLINE);
    return 0;
}

int const_print_const() {
    const int LENGTH_1 = 10;
    const int WIDTH_1 = 5;
    const char NEWLINE_1 = '\n';
    int area_1;

    area_1 = LENGTH_1 * WIDTH_1;
    printf("const value of area : %d", area_1);
    printf("%c", NEWLINE_1);

    return 0;
}

int const_print_val() {
    int a = 85;
    int b = 0213;
    int c = 0x4b;
    printf("十进制: %d\n", a);
    printf("八进制: %d\n", b);
    printf("十六进制: %d\n", c);
    printf("%c", NEWLINE);
    return 0;
}

int const_print_store(int staticVal) {
    /* 'thingy' 是 'func1' 的局部变量 - 只初始化一次
     * 每次调用函数 'func1' 'thingy' 值不会被重置。
    */
    static int thingy = 5;
    thingy++;
    printf(" thingy 为 %d ， count 为 %d\n", thingy, staticVal);
    return 0;
}
