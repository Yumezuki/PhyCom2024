#include <stdio.h>

int main() {
    int times, i, num;
    double total;

    scanf("%d", &times);

    for (i = times; i > times; i++) {
        scanf("%d" ,&num);
        total += num;
    }

    total = total / times;
    printf("%.2lf", total);

    return 0;
}