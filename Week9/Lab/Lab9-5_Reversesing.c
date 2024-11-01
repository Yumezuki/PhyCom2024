#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str;
    int size = 101;

    str = (char*) malloc(sizeof(char) * size);
    scanf("%[^\n]s", str);
    char *ptr = str;
    while (ptr < str + size && *ptr != '\0') {
        ptr++;
    }
    while ( ptr > str) {
        printf("%c", *--ptr);
    }
    printf("\n");
    free(str);
    return 0;

}