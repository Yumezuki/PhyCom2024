#include <stdio.h>

int main() {
    double num1, num2;

    scanf("%lf,%lf", &num1, &num2);

    printf("The sum of the given numbers : %lf\n", num1+num2);
    printf("The difference of the given numbers : %lf\n", num1-num2);
    printf("The product of the given numbers : %lf\n", num1*num2);
    printf("The quotient of the given numbers : %lf", num1/num2);

    return 0;
}