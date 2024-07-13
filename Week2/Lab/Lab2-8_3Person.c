#include <stdio.h>

int main() {
    char fname1[31], sname1[31], person2[65], person3[65];

    scanf("%s\n%s\n", &fname1, &sname1);
    scanf("%[^\n]\n", &person2);
    scanf("%[^\n]", &person3);

    printf("Person 1: %s %s\n", fname1, sname1);
    printf("Person 2: %s\n", person2);
    printf("Person 3: %s", person3);

    return 0;
}
