#include <stdio.h>
#include <string.h>

void removeChar(char* text) {
    int len = strlen(text);
    char temp[101];
    int i, j;
    int change = 1;

    while (change) {
        change = 0;
        j = 0;

        for (i = 0; i < len; i++) {
            if (text[i] != text[i + 1]) {
                temp[j++] = text[i];
            } else {
                while (text[i] == text[i + 1]) {
                    i++;
                }
                change = 1;
            }
        }
        temp[j] = '\0';
        if (change) {
            printf("%s\n", temp);
        }
        strcpy(text, temp);
        len = strlen(text);
    }

}

int main() {
    char text[101];
    scanf(" %[^\n]s", text);
    removeChar(text);
    
    return 0;
    
}