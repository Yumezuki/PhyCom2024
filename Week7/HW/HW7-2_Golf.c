#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

int main () {
    int degree, velocity;
    scanf("%d %d", &degree, &velocity);
    printf("theta (degree) : %d\nu (m/s) : %d\nh (m) : ", degree, velocity);
    double radian = degree * PI / 180, height;
    printf("%.4lf", (velocity * velocity) * (sin(radian) * sin(radian)) / (2 * 9.81));
}