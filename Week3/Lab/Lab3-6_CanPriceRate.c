#include <stdio.h>

int main() {
    double price, radius, height;

    scanf("%lf", &price);
    scanf("%lf", &radius);
    scanf("%lf", &height);

    double total = height*3.14159265359*(radius*radius);

    printf("Volume : %.2lfml\n", total);
    printf("Bath/ml : %.4lf", price/total);

    return 0;
}