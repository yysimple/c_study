#include <printf.h>
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
