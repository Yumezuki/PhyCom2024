#include <stdio.h>
#include <math.h>

void perimeter(double numA, double numB, double numC) {
    double res;
    res = numA + numB + numC;
    printf("Perimeter: %.2f\n", res);
}

void area(double height, double base) {
    double res;
    res = base * height;
    printf("Area: %.2f\n", res * 0.5);
}

int main() {
    double numA, numB, numC;
    scanf("%lf\n%lf", &numA, &numB);
    numC = numA*numA + numB * numB;
    numC = sqrt(numC);
    perimeter(numA, numB, numC);
    area(numA, numB);
    return 0;

}