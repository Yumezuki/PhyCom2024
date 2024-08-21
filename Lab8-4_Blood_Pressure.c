#include <stdio.h>

int main() {
    int sbp, dbp;

    scanf("%d\n%d", &sbp, &dbp);

    if (sbp > 120 && dbp > 80) {
        printf("Hypertension");
    } else {
        printf("Normal");
    }

    return 0;
}