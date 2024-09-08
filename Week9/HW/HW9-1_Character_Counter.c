#include <stdio.h>

int main() {
    char txt;
    int lowercase = 0, uppercase = 0, digits = 0;
    
    while (scanf("%c", &txt) == 1 && txt != '\n') {
        if (txt >= 'a' && txt <= 'z') {
            lowercase++;
        } else if (txt >= 'A' && txt <= 'Z') {
            uppercase++;
        } else if (txt >= '0' && txt <= '9') {
            digits++;
        }
    }

    printf("Lowercase letters: %d\n", lowercase);
    printf("Uppercase letters: %d\n", uppercase);
    printf("Digits: %d\n", digits);

    return 0;
}
