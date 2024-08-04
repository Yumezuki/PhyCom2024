#include <stdio.h>
#include <ctype.h>

int main() {
    char text;

    scanf("%c", &text);

    if (isdigit(text)) {
        printf("number");
    } else if (islower(text)) {
        printf("lowercase");        
    } else if (isupper(text)) {
        printf("uppercase");        
    } else {
        printf("error");    
    }

    return 0;
}