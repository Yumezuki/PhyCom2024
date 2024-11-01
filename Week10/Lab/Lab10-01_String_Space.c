#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str;
    int cap = 151;
    str = (char*) malloc(sizeof(char) * cap);
    scanf(" %[^\n]s", str);
    char *ptr = str;
    while (*ptr != '\0') {
        if (*ptr == ' ') {
            ptr++;
            continue;
        }
        printf("%c", *ptr++);
    }
    printf("\n");
    return 0;

}