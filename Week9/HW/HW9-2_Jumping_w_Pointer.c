#include <stdio.h>

int main() {
    int length, frequency;
    char txt;
    int count = 1;
    
    scanf("%d", &length);
    scanf("%d", &frequency);
    scanf("%*c");
    
     while (count <= length) {
        scanf("%c", &txt);

        if ((count - 1) / frequency * frequency == count - 1) { 
            putchar(txt);
        }
        
        count++;
    }

    return 0;
}
