#include <stdio.h>
#include <string.h>

int main() {
    char encrypt[27] = "QRMNCEDKLJOSHTUFVZGWIABXYP";
    char encryptSmall[27] = "qrmncedkljoshtufvzgwiabxyp";
    char text[201], res[201];
    scanf("%[^\n]", text);
    for (int i = 0; i <= strlen(text) - 1; i++) {
        if (text[i] == ' ') {
            res[i] = ' ';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            int index = (strchr(encrypt, text[i]) - encrypt + 26 - 5) % 26;
            res[i] = encrypt[index];
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            int index = (strchr(encryptSmall, text[i]) - encryptSmall + 26 - 5) % 26;
            res[i] = encryptSmall[index];
        }
    }
    res[strlen(text)] = '\0';

    printf("%s\n", res);
    return 0;

}