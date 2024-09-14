#include <stdio.h>
#include <stdlib.h>

int main() {
    char ch;
    char *str = (char *)malloc(100 * sizeof(char));
    char *ptr = str;
    char *endPtr;
    char temp; 

    if (str == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    while (scanf("%c", &ch) && ch != '-') {
        *ptr++ = ch;
    }
    *ptr = '\0';

    printf("%s", str);

    endPtr = ptr - 1; 
    while (endPtr >= str) {
        printf("%c", *endPtr--);
    }

    free(str);

    return 0;
}
