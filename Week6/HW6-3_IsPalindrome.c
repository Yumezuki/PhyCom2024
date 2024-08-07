#include <stdio.h>
#include <string.h>

int main()
{
    char text[] = " ", text_copy[] = " ";

    scanf("%s", text);
    
    int len = strlen(text), num = 0;

    for (int i = len; i > 0; i--) {
        text_copy[num] = text[i];
        num += 1;
    }

    printf("%s", );
    
    // if (text_copy == text) {
    //     printf("It is Palindrome.");
    // } else {
    //     printf("It is not Palindrome.");
    // }

    return 0;
}