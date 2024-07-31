#include <stdio.h>

int main() {
    int num, i;

    scanf("%d", &num);

    if (num > 0) {
        for (i = num; i > -1; i--) {
            printf("%d ", i);
        }
    } else {
        for (i = num; i < 1; i++) {
            printf("%d ", i);
        }
    }

    return 0;
}