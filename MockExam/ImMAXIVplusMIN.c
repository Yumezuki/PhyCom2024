// เลือกหาค่าที่มากที่สุดหรือค่าที่น้อยที่สุด จากเลขจำนวนเต็มทั้งหมด 5 จำนวน
// # ห้ามใช้ max(), min(), for, while , [], sort()

// Sample Input	 
// MAX
// 1
// 2
// 3
// 4
// 5
// Sample Output
// MAX : 5

// Sample Input	 
// MIN
// 10
// 9
// 8
// 7
// 6
// Sample Output
// MIN : 6

#include <stdio.h>
#include <string.h>

void isMax(int a, int b, int c, int d, int e) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    if (e > max) max = e;

    printf("MAX : %d\n", max);
}

void isMin(int a, int b, int c, int d, int e) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    if (e < min) min = e;

    printf("MIN : %d\n", min);
}

int main() {
    char txt[4];
    int a, b, c, d, e;
    scanf("%s", txt);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    scanf("%d", &e);
    if (strcmp(txt, "MAX") == 0) {
        isMax(a, b, c, d, e);
    } else {
        isMin(a, b, c, d, e);
    }

    return 0;
}