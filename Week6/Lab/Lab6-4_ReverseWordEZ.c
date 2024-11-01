#include <stdio.h>

int main() {
    char text[101];
    int length = 0;
    scanf("%[^\n]", text);
    while (text[length] != '\0') {
        length++;
    }
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", text[i]);
    }
    printf("\n");
    return 0;
}