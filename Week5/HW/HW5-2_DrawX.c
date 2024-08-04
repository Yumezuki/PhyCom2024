#include <stdio.h>
#include <stdlib.h>

int main () {
    int size, count, round;
    scanf("%d", &size);
    int center = (size - 1) / 2, back = size - 1;
    for (count = 0; count < size; count++) {
        for (round = 0; round < size; round++) {
            if (count == round || round == back) {
                printf("-");
            }
            else {
                printf("#");
            }
        }
        printf("\n");
        back--;
    }

    return 0;
}