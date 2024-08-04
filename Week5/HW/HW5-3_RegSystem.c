#include <stdio.h>

int main() {
    int age, height, weight, ppl_more20 = 0, ppl_less20 = 0, ppl_more30 = 0, ppl_less40 = 0, avg_a = 0,i;
    float avg_h = 0, avg_w = 0;

    for (i = 0; i < 50; i++) {
        scanf("%d %d %d", &age, &height, &weight);
        if (age >= 20 && height >= 160) {
            ppl_more20++;
        }
        if (age < 20 && (height <= 180 || weight >= 60)) {
            ppl_less20++;
        }
        if (age >= 30 && weight >= 40 && weight <= 80) {
            ppl_more30++;
        }
        if (age < 40 && (weight < 85 || height <= 200)) {
            ppl_less40++;
        }
        avg_a += age;
        avg_h += height;
        avg_w += weight;
    }
    printf("Age >= 20 and Height >= 160: %d\n", ppl_more20);
    printf("Age < 20 and Height <= 180 or Weight >= 60: %d\n", ppl_less20);
    printf("Age >= 30 and Weight >= 40 and Weight <= 80: %d\n", ppl_more30);
    printf("Age < 40 and Weight < 85 or Height <= 200: %d\n", ppl_less40);
    printf("Average Age: %d\n", avg_a / 50);
    printf("Average Height: %.2f\n", avg_h / 50);
    printf("Average Weight: %.2f", avg_w / 50);

    return 0;
}