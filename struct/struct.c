#include <string.h>
#include "struct.h"
#include <stdio.h>

struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

void use_struct() {
    struct Books Book1;        /* 声明 Book1，类型为 Books */
    struct Books Book2;        /* 声明 Book2，类型为 Books */

    /* Book1 详述 */
    strcpy(Book1.title, "C Programming");
    strcpy(Book1.author, "Nuha Ali");
    strcpy(Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495407;

    /* Book2 详述 */
    strcpy(Book2.title, "Telecom Billing");
    strcpy(Book2.author, "Zara Ali");
    strcpy(Book2.subject, "Telecom Billing Tutorial");
    Book2.book_id = 6495700;

    /* 输出 Book1 信息 */
    printf("Book 1 title : %s\n", Book1.title);
    printf("Book 1 author : %s\n", Book1.author);
    printf("Book 1 subject : %s\n", Book1.subject);
    printf("Book 1 book_id : %d\n", Book1.book_id);

    /* 输出 Book2 信息 */
    printf("Book 2 title : %s\n", Book2.title);
    printf("Book 2 author : %s\n", Book2.author);
    printf("Book 2 subject : %s\n", Book2.subject);
    printf("Book 2 book_id : %d\n", Book2.book_id);

}

union Data {
    int i;
    float f;
    char str[20];
};

void cover_address_use() {
    union Data data;
    data.i = 10;
    data.f = 220.5;
    strcpy( data.str, "C Programming");

    printf( "data.i : %d\n", data.i);
    printf( "data.f : %f\n", data.f);
    printf( "data.str : %s\n", data.str);
}

void union_use() {
    union Data data;
    data.i = 10;
    printf("data.i : %d\n", data.i);
    data.f = 220.5;
    printf("data.f : %f\n", data.f);
    strcpy(data.str, "C Programming");
    printf("data.str : %s\n", data.str);
}
