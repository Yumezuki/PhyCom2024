#include <stdio.h>
#include <string.h>
#include <ctype.h>

void insertion_sort(char nameList[][200], int num) {
    for (int i = 1; i < num; i++) {
        char key[200];
        strcpy(key, nameList[i]);
        int j = i - 1;

        while (j >= 0 && strcmp(key, nameList[j]) < 0) {
            strcpy(nameList[j + 1], nameList[j]);
            j -= 1;
        }
        strcpy(nameList[j + 1], key);
    }
}

void formatName(char *name);

int main() {
    int count = 0, num;
    scanf("%d", &num);
    char name[200], nameList[num][200];
    for (int i = 0; i < num; i++) {
        scanf(" %[^\n]", name);
        formatName(name);
        strcpy(nameList[count], name);
        count++;
    }

    insertion_sort(nameList, count);

    for (int i = 0; i < count; i++) {
        printf("%s\n", nameList[i]);
    }
    return 0;

}

void formatName(char *name) {
    int len = strlen(name);
    name[0] = toupper(name[0]);
    for (int i = 1; i < len; i++) {
        if (name[i - 1] == ' ') {
            name[i] = toupper(name[i]);
        } else {
            name[i] = tolower(name[i]);
        }
    }
}