#include <stdio.h>

int main() {
    double matrix[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) {
        printf("This is a scalar matrix");
    } else {
        printf("This is not a scalar matrix");
    }

    return 0;
}