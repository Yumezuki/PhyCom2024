#include <stdio.h>
#include <string.h>

int main() {
    char name[101], surname[101];
    scanf("%s %s", name, surname);
    printf("%c.%c.\n", name[0], surname[0]);

    return 0;

}