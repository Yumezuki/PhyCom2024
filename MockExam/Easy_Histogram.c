// ช่วยพี่เชฟเอียนหา Histogram ของ String ดังกล่าวหน่อย โดยเรียงจากตัว aA ถึง zZ และนับตัวอักษรว่ามีกี่ตัว ภาษา C

// Sample Input
// Amazon

// Sample Output
// a = 1
// A = 1
// m = 1
// n = 1
// o = 1
// z = 1

// Sample Input
// Ratri and Tida

// Sample Output
// a = 3
// d = 2
// i = 2
// n = 1
// r = 1
// R = 1
// t = 1
// T = 1

// โดยเรียง a A b B c C จนถึง z Z และมีการ input แบบเว้นวรรค (ฉะนั้นต้องใช้ %[^\n])

#include <stdio.h>
#include <ctype.h>

void printHistogram(char *str) {
    int count[52] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) {
            count[str[i] - 'a']++;
        } else if (isupper(str[i])) {
            count[str[i] - 'A' + 26]++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            printf("%c = %d\n", 'a' + i, count[i]);
        }
        if (count[i + 26] > 0) {
            printf("%c = %d\n", 'A' + i, count[i + 26]);
        }
    }
}

int main() {
    char str[100];
    scanf("%[^\n]", str);
    printHistogram(str);
    
    return 0;
}
