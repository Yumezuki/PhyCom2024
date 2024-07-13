#include <stdio.h>

int main() {
    char txt1, txt2, txt3, txt4, txt5;

    scanf("%c\n%c\n%c\n%c\n%c", &txt1, &txt2, &txt3, &txt4, &txt5);

    printf("%c\n%c\n%c\n%c\n%c", txt1+1, txt2, txt3+1, txt4, txt5+1);

    return 0;
}
