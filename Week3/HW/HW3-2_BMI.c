#include <stdio.h>

int main() {
    float height, weight;

    scanf("%f", &height);
    scanf("%f", &weight);

    height = height/100;

    printf("%f", weight/(height*height));

    return 0;
}