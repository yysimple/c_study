#include <stdio.h>
# include "type.h"

void type_print() {
    char a = 'a';
    short int b = 10;
    int c;
    long int d;
    float e;
    double f;
    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(b));
    printf("%d\n", sizeof(c));
    printf("%d\n", sizeof(d));
    printf("%d\n", sizeof(e));
    printf("%d\n", sizeof(f));
}
