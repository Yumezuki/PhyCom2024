#include <stdio.h>
#include <string.h>

int main() {
    int charCount = 0, wordCount = 0, lineCount = 0;
    char text[451];
    while (1) {
        scanf(" %[^\n]s", text);
        if (strcmp(text, ".") == 0) {
            break;
        }
        lineCount++;

        for (int i = 0; i < strlen(text); i++) {
            if (text[i] == ' ') {
                wordCount++;
            } else {
                charCount++;
            }
        }
        wordCount++;
    }
    printf("Char = %d, word = %d, line = %d\n", charCount, wordCount, lineCount);
    return 0;

}