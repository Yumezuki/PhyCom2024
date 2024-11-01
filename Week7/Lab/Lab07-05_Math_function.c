#include <stdio.h>

double findMin(double array[], int size);
double findMax(double array[], int size);
double findAvg(double array[], int size);

double getValue() {
    double value;
    scanf("%lf", &value);
    return value;
}
int main() {
    int n;
    scanf("%d", &n);

    double array[n];
    for (int i = 0; i < n; i++) {
        array[i] = getValue();
    }

    double min, max, avg;
    min = findMin(array, n);
    max = findMax(array, n);
    avg = findAvg(array, n);

    printf("%d Values\n", n);
    printf("Min: %.3f\n", min);
    printf("Max: %.3f\n", max);
    printf("Avg: %.3f\n", avg);

    return 0;
}

double findMin(double array[], int size) {
    double min;
    int i;
    min = array[0];
    for (i = 0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

double findMax(double array[], int size) {
    double max;
    int i;
    max = array[0];
    for (i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

double findAvg(double array[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}