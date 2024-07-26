#include <stdio.h>

int main () {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a + b > c & a + c > b & b + c > a) {
        printf("Triangle is valid.");
    }
    else {
        printf("Triangle is not valid.");
    }
}