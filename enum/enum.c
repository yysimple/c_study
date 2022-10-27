
/* 可以使用常量的方式来定义，跟java里面差不多 */
#include <printf.h>
#include "enum.h"

int enum_test() {
    enum DAY day;
    day = WED;
    printf("day == %d\n", day);

    // 遍历枚举元素
    for (day = MON; day <= SUN; day++) {
        printf("枚举元素：%d \n", day);
    }
    return 0;
}

/**
 * 不连续的枚举类是不支持遍历的
 * @return
 */
int no_discontinuity() {
    enum {
        ENUM_0,
        ENUM_10 = 10,
        ENUM_11
    };
}

int enum_switch() {
    enum color {
        red = 1, green, blue
    };

    enum color favorite_color;

    /* 用户输入数字来选择颜色 */
    printf("请输入你喜欢的颜色: (1. red, 2. green, 3. blue): ");
    scanf("%u", &favorite_color);

    /* 输出结果 */
    switch (favorite_color) {
        case red:
            printf("你喜欢的颜色是红色");
            break;
        case green:
            printf("你喜欢的颜色是绿色");
            break;
        case blue:
            printf("你喜欢的颜色是蓝色");
            break;
        default:
            printf("你没有选择你喜欢的颜色");
    }

    return 0;
}

