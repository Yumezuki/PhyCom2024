#include <stdio.h>
#include <string.h>

int main() {
    int lenght;
    char firstLine[51], secondLine[41];
    scanf("%d", &lenght);
    scanf(" %[^\n]s", firstLine);
    scanf(" %[^\n]s", secondLine);
    for (int i = 0; i < lenght; i++) {
        printf("*");
    }
    printf("\n");
    

    printf("*");
    int paddingLeft = (lenght - strlen(firstLine) - 1) / 2;
    for (int i = 0; i < paddingLeft; i++) {
        printf(" ");
    }
    printf("%s", firstLine);
    int paddingRight = lenght - strlen(firstLine) - paddingLeft - 2;
    for (int i = 0; i < paddingRight; i++) {
        printf(" ");
    }
    printf("*\n");


    printf("*");
    paddingLeft = (lenght - strlen(secondLine) - 1) / 2;
    for (int i = 0; i < paddingLeft; i++) {
        printf(" ");
    }
    printf("%s", secondLine);
    paddingRight = lenght - strlen(secondLine) - paddingLeft - 2;
    for (int i = 0; i < paddingRight; i++) {
        printf(" ");
    }
    printf("*\n");


    for (int i = 0; i < lenght; i++) {
        printf("*");
    }
    printf("\n");
    return 0;

}