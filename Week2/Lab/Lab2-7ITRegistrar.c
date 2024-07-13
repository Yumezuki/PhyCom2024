#include <stdio.h>

int main() {
    char name[31], surname[31], std_id[9];
    int day, month, year;
    float gpa;

    scanf("%s\n%s\n%s\n", &name, &surname, &std_id);
    scanf("%d/%d/%d\n", &day, &month, &year);
    scanf("%f",&gpa);

    printf("Fullname: %s %s\nID: %s\nDOB: %02d-%02d-%02d\nGPA: %.2f", name, surname, std_id, day, month, year, gpa);
    return 0;
}
