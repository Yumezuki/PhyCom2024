#include <stdio.h>
#define ROWS 3
#define COLS 3

int main() {
    double mat1[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        scanf("%lf %lf %lf", &mat1[i][0], &mat1[i][1], &mat1[i][2]);
    }
    if ((mat1[0][0] == mat1[1][1] && mat1[1][1] == mat1[2][2]) 
    && (mat1[0][1] == 0.0 && mat1[0][2] == 0.0 && mat1[1][0] == 0.0 
    && mat1[1][2] == 0.0 && mat1[2][0] == 0.0 && mat1[2][1] == 0.0)) {
        printf("This is a scalar matrix");
    } else {
        printf("This is not a scalar matrix");
    }
    return 0;
}