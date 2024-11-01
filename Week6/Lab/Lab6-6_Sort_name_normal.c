#include <stdio.h>
#include <string.h>
#include <ctype.h>

void insertion_sort(char nameList[21][122], int num) {
    for (int i = 1; i < num; i++) {
        char key[122];
        strcpy(key, nameList[i]);
        int j = i - 1;

        while (j >= 0 && strcmp(key, nameList[j]) < 0) {
            strcpy(nameList[j + 1], nameList[j]);
            j -= 1;
        }
        strcpy(nameList[j + 1], key);
    }
}

int main() {
    char name[61], surname[61], reName[61], reSurname[61], res[122], nameList[21][122];
    int count = 0;
    for (int i = 1; i <= 20; i++) {
        nameList[i][0] = '\0';
        scanf("%34s %34s", name, surname);
        reName[0] = toupper(name[0]);
        for (int j = 1; name[j] != '\0'; j++) {
            reName[j] = tolower(name[j]);
        }
        reName[strlen(name)] = '\0';

        reSurname[0] = toupper(surname[0]);
        for (int j = 1; surname[j] != '\0'; j++) {
            reSurname[j] = tolower(surname[j]);
        }
        reSurname[strlen(surname)] = '\0';
        snprintf(res, sizeof(res), "%s %s", reName, reSurname);
        strcpy(nameList[count], res);
        count++;
    }

    insertion_sort(nameList, count);

    for (int i = 0; i < count; i++) {
        printf("%s\n", nameList[i]);
    }
    return 0;

}