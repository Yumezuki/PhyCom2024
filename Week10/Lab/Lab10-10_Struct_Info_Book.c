#include <stdio.h>
#include <string.h>

struct Student_Info {
    char name[61];
    char surname[61];
    char sex[7];
    int age;
    char ID[13];
    double gpa;
};

int main() {
    struct Student_Info std;
    scanf("%s %s %s %d %s %lf", std.name, std.surname, std.sex, &std.age, std.ID, &std.gpa);
    if (strcmp(std.sex, "Male") == 0) {
        printf("Mr %c %s (%d) ID: %s GPA %.2f\n", std.name[0], std.surname, std.age, std.ID, std.gpa);
    } else if (strcmp(std.sex, "Female") == 0) {
        printf("Miss %c %s (%d) ID: %s GPA %.2f\n", std.name[0], std.surname, std.age, std.ID, std.gpa);
    }
    return 0;

}