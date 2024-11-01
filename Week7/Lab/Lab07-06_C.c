#include <stdio.h>
#include <math.h>

int main() {
    long numA, numB;
    scanf("%ld %ld", &numA, &numB);
    printf("sqrt(%ld^2+%ld^2)=%.2f\n", numA, numB, sqrt(numA*numA + numB*numB));
    return 0;

}