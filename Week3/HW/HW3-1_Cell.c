#include <stdio.h>

int main() {
    char text[4];

    scanf("%s", text);
    printf("*****\n");
    printf("*-*-*\n");
    printf("*%s*\n", text);
    printf("*-*-*\n");
    printf("*****");

    return 0;
}