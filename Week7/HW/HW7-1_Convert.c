#include <stdio.h>
#include <string.h>

void swapcase (char *str) {
    for (int i = 0; str[i] != '\0'; i ++) {
        if (65 <= str[i] && str[i] <= 90) {
            printf("%c", (int) str[i] + 32);
        } else if (97 <= str[i] && str[i] <= 122) {
            printf("%c", (int) str[i] - 32);
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}

int main () {
    char str[101], str2[101];
    scanf("%[^\n]s", str);
    getchar();
    scanf("%[^\n]s", str2);
    printf("*** Results ***\n");
    swapcase(str);
    swapcase(str2);
    printf("***************\n");
    if (strcasecmp(str, str2) == 0) {
        printf("Both strings are the same.");
    } else {
        printf("Both strings are not the same.");
    }
}