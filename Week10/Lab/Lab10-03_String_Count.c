#include <stdio.h>
#include <stdlib.h>

int main() {
    char find;
    char *str;
    str = (char*)malloc(sizeof(char) * 151);
    scanf("%c", &find);
    if (find >= 60 && find <= 90) { find += 32;}
    scanf(" %[^\n]s", str);
    int count = 0;
    char *ptr = str;
    while (*ptr != '\0') {
        if (*ptr >= 65 && *ptr <= 90) {
            *ptr += 32;
        }
        if (*ptr == find) {
            count++;
        }
        ptr++;
    }
    printf("%d\n", count);
    free(str);

    return 0;

}