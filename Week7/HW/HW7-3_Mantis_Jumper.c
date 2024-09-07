#include <stdio.h>

int fibonacci (int floorLevel) {
    int method[floorLevel + 1];
    method[0] = 0;
    method[1] = 1;
    for (int i = 2; i <= floorLevel; i ++) {
        method[i] = method[i - 1] + method[i - 2];
    }
    return method[floorLevel];

}

int main () {
    int floor;
    scanf("%d", &floor);
    printf("method = %d", fibonacci(floor + 1));
}