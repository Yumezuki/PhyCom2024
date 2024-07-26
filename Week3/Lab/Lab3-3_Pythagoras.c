#include <stdio.h>
#include <math.h>

int main() {
    double num1, num2;

    scanf("%lf%lf", &num1, &num2);
    printf("%.2lf", sqrt(pow(num1, 2) + pow(num2, 2)));

    return 0;
}