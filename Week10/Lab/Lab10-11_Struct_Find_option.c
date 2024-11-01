#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Student_Info {
    char name[61];
    char surname[61];
    char sex[7];
    int age;
    char ID[13];
    double gpa;
};

void insertion_sort(struct Student_Info std[], int n, char sortby[]) {
    for (int i = 1; i < n; i++) {
        struct Student_Info key = std[i];
        int j = i - 1;

        if (strcmp(sortby, "name") == 0) {
            while (j >= 0 && strcmp(std[j].name, key.name) > 0) {
                std[j + 1] = std[j];
                j--;
            }
        } else if (strcmp(sortby, "surname") == 0) {
            while (j >= 0 && strcmp(std[j].surname, key.surname) > 0) {
                std[j + 1] = std[j];
                j--;
            }
        } else if (strcmp(sortby, "id") == 0) {
            while (j >= 0 && strcmp(std[j].ID, key.ID) > 0) {
                std[j + 1] = std[j];
                j--;
            }
        }

        std[j + 1] = key;
    }
}

int main() {
    struct Student_Info std[20];
    for (int i = 0; i < 20; i++) {
        scanf("%s %s %s %d %s %lf", std[i].name, std[i].surname, std[i].sex, &std[i].age, std[i].ID, &std[i].gpa);
    }
    char sortby[8];
    scanf("%s", sortby);
    for (int i = 0; i < strlen(sortby); i++) {
        sortby[i] = tolower(sortby[i]);
    }
    
    insertion_sort(std, 20, sortby);

    for (int i = 0; i < 20; i++) {
        printf("%s %c %s (%d) ID: %s GPA %.2f\n", (strcmp(std[i].sex, "Male") == 0) ? "Mr" : "Miss", std[i].name[0], std[i].surname, std[i].age, std[i].ID, std[i].gpa);
    }

    return 0;

}