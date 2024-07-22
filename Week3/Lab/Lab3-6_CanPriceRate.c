#include <stdio.h>

int main() {
    double price, radius, height;

    scanf("%d", &price);
    scanf("%f", &radius);
    scanf("%d", &height);

    double total = height*3.14159265359*(radius*radius);

    printf("%f", radius);

    // printf("Volume : %.2fml\n", total);
    // printf("Bath/ml : %.4f", price/total);

    return 0;
}