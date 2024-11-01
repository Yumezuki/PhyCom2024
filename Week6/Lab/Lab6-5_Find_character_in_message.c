#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[301], find, copy;
    int collect[301];
    int found = 0, count = 0;
    scanf("%[^\n]\n", text);
    for (int i = 0; text[i]; i++) {
        text[i] = tolower(text[i]);
    }
    scanf("%c", &find);
    copy = find;
    find = tolower(find);

    for (int i = 0; i <= strlen(text); i++) {
        if (find == text[i]) {
            count++;
            collect[count] = i + 1;
            found = 1;
        }
    }
    if (found != 0) {
        printf("There is/are %d \"%c\" in the above sentences.\n", count, copy);
        printf("Position: ");
        for (int i = 1; i <= count; i++) {
            printf("%d", collect[i]);
            if (i <= count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    } else {
        printf("Not found.\n");
    }
    return 0;
}