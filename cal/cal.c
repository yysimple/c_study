//
// Created by cheng xing wu on 2022/10/27.
//
#include <stdio.h>
#include "cal.h"

void cal_base_result() {
    int a = 21;
    int b = 10;
    int c;

    c = a + b;
    printf("Line 1 - c 的值是 %d\n", c);
    c = a - b;
    printf("Line 2 - c 的值是 %d\n", c);
    c = a * b;
    printf("Line 3 - c 的值是 %d\n", c);
    c = a / b;
    printf("Line 4 - c 的值是 %d\n", c);
    c = a % b;
    printf("Line 5 - c 的值是 %d\n", c);
    c = a++;  // 赋值后再加 1 ，c 为 21，a 为 22
    printf("Line 6 - c 的值是 %d\n", c);
    c = a--;  // 赋值后再减 1 ，c 为 22 ，a 为 21
    printf("Line 7 - c 的值是 %d\n", c);
}

/*
 * 加减运算，跟java是一样的
 */
void cal_base_result01() {
    int c;
    int a = 10;
    c = a++;
    printf("先赋值后运算：\n");
    printf("Line 1 - c 的值是 %d\n", c);
    printf("Line 2 - a 的值是 %d\n", a);
    a = 10;
    c = a--;
    printf("Line 3 - c 的值是 %d\n", c);
    printf("Line 4 - a 的值是 %d\n", a);

    printf("先运算后赋值：\n");
    a = 10;
    c = ++a;
    printf("Line 5 - c 的值是 %d\n", c);
    printf("Line 6 - a 的值是 %d\n", a);
    a = 10;
    c = --a;
    printf("Line 7 - c 的值是 %d\n", c);
    printf("Line 8 - a 的值是 %d\n", a);
}

/*
 * 条件控制语句
 */
void condition_test() {
    int val = 10;
    for (int i = 0; i < val; ++i) {
        printf("我是for循环：%d\n", i);
    }

    while (val < 1) {
        val--;
        printf("我是while循环：%d\n", val);
    }
}