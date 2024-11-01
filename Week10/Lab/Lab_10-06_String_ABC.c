#include <stdio.h>
#include <string.h>

void insertion_sort(char text[201]) {
    int num = strlen(text);

    for (int i = 0; i < num; i++) {
        char key = text[i];
        int j = i - 1;

        while (j >= 0 && text[j] > key && text[j + 1] != '\0') {
            text[j + 1] = text[j];
            j -= 1;
        }
        text[j + 1] = key;
    }
}

int main() {
    char text[201];
    scanf("%s", text);
    insertion_sort(text);
    printf("%s\n", text);

    return 0;

}