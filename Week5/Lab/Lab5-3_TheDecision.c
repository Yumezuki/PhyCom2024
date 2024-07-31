#include <stdio.h>

int main() {
    int num1, num2;

    scanf("%d %d", &num1, &num2);

    if (num1 > num2) {
        while (num1 > num2-1) {
            printf("%d ", num1);
            num1--;
        }
    } else {
        while (num1 < num2+1) {
            printf("%d ", num1);
            num1++;
        }
    }

    return 0;
}