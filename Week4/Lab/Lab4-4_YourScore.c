#include <stdio.h>

int main() {
    float score;

    scanf("%f", &score);

    if (score >= 80 && score <=100) {
        printf("A");
    } else if (score >= 70 && score < 80) {
        printf("B");        
    } else if (score >= 60 && score < 70) {
        printf("C");    
    } else if (score >= 50 && score < 60) {
        printf("D");    
    } else if (score >= 0 && score < 50) {
        printf("F");    
    } else {
        printf("Out of Range");
    }

    return 0;
}