#include <stdio.h>

int main() {
    int num, found = 0, i;

    int M[] = {2, 20, 8, 10, 4, 6, 16, 18};
    int N[] = {1, 3, 9, 7, 11, 15, 19};

    while (1) {
        scanf("%d", &num);

        if (num > 0 && num < 21) {
            break;
        }
    }

    for (i = 0; i < 8; i++) {
        if (M[i] == num) {
            printf("%d is in M at index [%d]", num, i);
            found = 1;
            break;
        }

        else if (N[i] == num) {
            printf("%d is in N at index [%d]", num, i);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("%d is not in neither M nor N", num);
    }

    return 0;
}