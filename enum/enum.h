#define MON_DEF  1
#define TUE_DEF  2
#define WED_DEF  3
#define THU_DEF  4
#define FRI_DEF  5
#define SAT_DEF  6
#define SUN_DEF  7

/* 这里定义 MON = 1 之后，其他的在枚举里面就会自增 */
enum DAY {
    MON = 1, TUE, WED, THU, FRI, SAT, SUN
};

int enum_test();

int enum_switch();