#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[2001];
    scanf("%[^\n]s", text);
    for (int i = 0; i < strlen(text); i++) {
        text[i] = tolower(text[i]);
    }
    char find[4] = "cat";
    char *res = strstr(text, find);
    while (res != NULL) {
        printf("%ld", res - text);
        res = strstr(res + 1, find);
        if ( res == NULL) {
            break;
        }
        printf(", ");
    }
    printf("\n");
    return 0;

}