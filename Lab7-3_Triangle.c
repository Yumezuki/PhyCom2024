#include <stdio.h>
#include <math.h>

int perimeter(double x, double y, double z);
int area(double x, double y);

int main() {
    double a, b, c, result_area, result_perimeter;

    scanf("%lf %lf", &a, &b);

    c = pow(a, 2.0) + pow(b, 2.0);
    c = sqrt(c);

    result_area = area(a, b);
    result_perimeter = perimeter(a, b, c);

    printf("Perimeter: %lf\n", result_perimeter);
    printf("Area: %lf", result_area);
    
    return 0;
}

int area(double x, double y) {

    return (1.0 / 2.0) * y * x;
}

int perimeter(double x, double y, double z) {

    return x + y + z;
}
