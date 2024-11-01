#include <stdio.h>
#include <string.h>

struct Book {
    char id[10];
    char name[100];
    char author[100];
};

int main() {
    int num, found = 0;
    char find[4];
    scanf("%d\n%s", &num, find);
    struct Book book[num];
    for (int i = 0; i < num; i++) {
        scanf("%s %s %s", book[i].id, book[i].name, book[i].author);
        if (strcmp(book[i].id, find) == 0) {
            printf("%s %s %s\n", book[i].id, book[i].name, book[i].author);
            found = 1;
            return 0;
        }
    }
    if (!(found)) {
        printf("Not Found\n");
    }
    return 0;

}