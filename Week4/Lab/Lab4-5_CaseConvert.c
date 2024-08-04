#include <stdio.h>

int main() {
    char text;

    scanf("%c", &text);

    if (text >= 'a' && text <='z') {
        printf("%c", text - 'a' + 'A');
    } else if (text >= 'A' && text <='Z') {
        printf("%c", text - 'A' + 'a');        
    } else {
        printf("error");    
    }

    return 0;
}