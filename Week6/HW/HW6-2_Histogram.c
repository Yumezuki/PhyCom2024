#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main() {
    char alp, checker[100];
    int num, i, j, trigger, checker_count = 0;
    int counter[100] = {0};
    scanf("%d", &num);
    getchar();
    for (i = 0; i < num; i++){
        scanf("%c", &alp);
        getchar();
        alp = tolower(alp);
        trigger = 0;
 
        for (j = 0; j < checker_count; j++) {
            if (checker[j] == alp) {
                counter[j]++; 
                trigger = 1;
                break;
            }
        }
 
        if (!trigger) {
            checker[checker_count] = alp;
            counter[checker_count] = 1; 
            checker_count++;
        }
    }
    for (i = 0; i < checker_count; i++){
        printf("%c: %d\n", checker[i], counter[i]);
    }
    return 0;
}