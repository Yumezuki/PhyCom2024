#include <stdio.h>

int main() {
    char string1[30], string2[30], string3[30], string4[30];
    scanf("%s\n%s\n%s\n%s", &string1, &string2, &string3, &string4);

    printf("String 1: %.3s\nString 2: %.4s\nString 3: %.5s\nString 4: %.6s\n", string1,string2,string3,string4);
    return 0;
}