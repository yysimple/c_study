#include "pre.h"
#include <stdio.h>

void const_define() {
    printf("File :%s\n", __FILE__);
    printf("Date :%s\n", __DATE__);
    printf("Time :%s\n", __TIME__);
    printf("Line :%d\n", __LINE__);
    printf("ANSI :%d\n", __STDC__);
}

#define  message_for(a, b)  \
    printf(#a " and " #b ": We love you!\n")
#define square(x) ((x) * (x))

int param_define() {
    message_for(haha, hihi);
    printf("结果：%d\n", square(2));
    return 0;
}