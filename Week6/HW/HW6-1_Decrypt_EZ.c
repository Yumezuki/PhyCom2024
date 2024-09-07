#include <stdio.h>

int main () {
    char cipher[62] = {'A', 'B', 'X', 'Y', 'P', 'Q', 'R', 'M', 'N', 'C', 'E', 'D', 'K', 'L', 'J', 'O',
                    'S', 'H', 'T', 'U', 'F', 'V', 'Z', 'G', 'W', 'I', 'A', 'B', 'X', 'Y', 'P', 'a', 'b',
                    'x', 'y', 'p', 'q', 'r', 'm', 'n', 'c', 'e', 'd', 'k', 'l', 'j', 'o', 's', 'h', 't',
                    'u', 'f', 'v', 'z', 'g', 'w', 'i', 'a', 'b', 'x', 'y', 'p'};
    char input[200];

    scanf("%[^\n]s", input);

    for (int i = 0; input[i] != '\0'; i ++) {
        for (int j = 0; j < 62; j ++) {
            if (input[i] == cipher[j]) {
                printf("%c", cipher[j + 5]);
                break;
            } else if (input[i] == ' ') {
                printf("%c", ' ');
                break;
            }
        }
    }

    return 0;
}