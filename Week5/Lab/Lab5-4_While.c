#include <stdio.h>

int main() {
    int num, i = 1;

    scanf("%d", &num);

    while (i < num+1) {
        printf("%d ", i);
        i++;
    }

    return 0;
}