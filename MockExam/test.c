#include <stdio.h>

int main(void) {
    int a=14, *p=&a, **q=&p;
    printf("%d\n", a);
    printf("%d\n", p);
    printf("%d\n", q);
    printf("%d\n", &a);
    printf("%d\n", &p);
    printf("%d\n", &q);
    printf("%d\n", *p);
    printf("%d\n", *q);
    printf("%d\n", **q);

    return 0;
}