#include <stdio.h>
#include <math.h>

void insertion_sort(double numList[], int num) {
    for (int i = 0; i < num; i++) {
        double key;
        key = numList[i];
        int j = i - 1;

        while (j >= 0 && numList[j] > key) {
            numList[j + 1] = numList[j];
            j -= 1;
        }
        numList[j + 1] = key;
    }
}

int main() {
    int num;
    double value, avg = 0, med = 0, sum = 0.0, variance = 0.0;
    scanf("%d", &num);
    double numList[num];
    for (int i = 0; i < num; i++) {
        scanf("%lf", &value);
        sum += value;
        numList[i] = value;
    }
    avg = sum / num;
    insertion_sort(numList, num);
    if (num % 2 == 0) {
        med = (numList[(num - 1) / 2] + numList[num / 2]) / 2.0;
    } else {
        med = numList[num / 2];
    }
    for (int i = 0; i < num; i++) {
        variance += pow(numList[i] - avg, 2);
    }
    variance /= num;
    variance = sqrt(variance);
    printf("%.2lf\n", avg);
    printf("%.2lf\n", med);
    printf("%.2lf\n", variance);
    return 0;
}