#include <printf.h>
#include "constant.h"


#define LENGTH 10
#define WIDTH  5
#define NEWLINE '\n'

int const_print() {
    int area;
    area = LENGTH * WIDTH;
    printf("value of area : %d", area);
    printf("%c", NEWLINE);
    return 0;
}
