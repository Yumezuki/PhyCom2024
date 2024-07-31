#include <stdio.h>

int main() {
    int num, total, i;

    for (i = 1; i > 0; i++) {
        scanf("%d", &num);
        if (num == -9) {
            break;
        } else {
            total += num;
        }
    }
    printf("%d", total);

    return 0;
}