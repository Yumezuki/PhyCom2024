#include <stdio.h>

int main()
{
    char num[5];

    scanf("%s", &num);

    printf("%s%.2s", num+2, num);

    return 0;
}
