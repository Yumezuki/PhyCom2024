#include <stdio.h>

int main() {
    double matrix1[3][3], matrix2[3][3], result[3][3];
    double num;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }

    printf("A x B\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%.2lf ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}