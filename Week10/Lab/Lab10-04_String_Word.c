#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[151];
    scanf(" %[^\n]s", text);
    for (int i = 0; i < strlen(text); i++) {
        text[i] = tolower(text[i]);
    }
    int index = 0, word = 0;
    while (text[index] != '\0') {
        if (text[index] == ' ') {
            word++;
        }
        index++;
    }
    printf("%d words\n", word + 1);
    printf("----\n");
    int count = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] != ' ') {
            printf("%c", text[i]);
            count++;
        } else {
            printf(" : %d\n", count);
            count = 0;
        }
    }

    if (count > 0) {
        printf(" : %d\n", count);
    }

    return 0;
}