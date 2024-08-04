#include <stdio.h>
#include <ctype.h>

int main() {
    char grade;

    scanf("%c", &grade);

    switch (toupper(grade)) {
        // toupper คือ uppercase หรือก็คือเปลี่ยนตัวเล็กเป็นตัวใหญ่
    case 'A':
        printf("Genius");
        break;
    
    case 'B':
        printf("Good");
        break;

    case 'C':
        printf("Try Harder");
        break;

    case 'D':
        printf("Very Bad");
        break;

    case 'F':
        printf("Fail");
        break;

    default:
        printf("Invalid Input");
        break;
    }

    return 0;
}