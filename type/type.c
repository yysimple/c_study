#include <stdio.h>
#include <float.h>
# include "type.h"

void type_print() {
    char a = 'a';
    short int b = 10;
    int c;
    long int d;
    float e;
    double f;
    printf("%lu\n", sizeof(a));
    printf("%d\n", sizeof(b));
    printf("%d\n", sizeof(c));
    printf("%d\n", sizeof(d));
    printf("%d\n", sizeof(e));
    printf("%d\n", sizeof(f));

    printf("float 存储最大字节数 : %lu \n", sizeof(float));
    printf("float 最小值: %E\n", FLT_MIN );
    printf("float 最大值: %E\n", FLT_MAX );
    printf("精度值: %d\n", FLT_DIG );
}
