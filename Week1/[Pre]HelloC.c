#include <stdio.h>

int main()
{
    char std_id[8], fullname[50];
    scanf("%s\n%[^\n]", std_id, fullname);
    printf("Hello! My name is %s, %s\n", fullname, std_id);
    return 0;
}
