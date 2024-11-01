#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str, word;
    int size = 0, cap = 10;

    str = (char*) malloc(sizeof(char) * cap);

    while (1) {
        scanf(" %c", &word);
        if (word == '-') {
            break;
        }
        if (size >= cap) {
            cap *= 2;
            char *temp = (char*) realloc(str, sizeof(char) * cap);
            str = temp;
        }

        *(str + size++) = word;
    }
    char *ptr = str;
    while (ptr < str + size) {
        printf("%c", *ptr++);
    }
    printf("\n");
    while (ptr > str) {
        printf("%c", *--ptr);
    }
    printf("\n");
    free(str);
    return 0;
    
}