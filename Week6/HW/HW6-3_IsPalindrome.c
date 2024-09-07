#include <stdio.h>
#include <string.h>

int main () {
    char txt[100];
    scanf("%s", txt);
    int size = strlen(txt);
    for (int i = 0; i < size / 2; i ++) {
        if (txt[i] != txt[size - i - 1]) {
            printf("It is not Palindrome.");
            return 0;
        }
    }
    printf("It is Palindrome.");
}