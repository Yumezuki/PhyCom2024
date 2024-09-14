#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    char id[10];
    char name[100];
    long salary;
    long sales;
};

void display_record(struct Record *record) {
    double commission = 0.02 * record->sales;
    double total_income = record->salary + commission;
    
    printf("%s\n", record->id);
    printf("%s\n", record->name);
    printf("%ld\n", record->sales);
    printf("%.2f\n", commission);
    printf("%ld\n", record->salary);
    printf("%.2f\n", total_income);
}

int find_record(struct Record *records, int n, const char *id, struct Record *result) {
    for (int i = 0; i < n; ++i) {
        if (strcmp(records[i].id, id) == 0) {
            *result = records[i];
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    struct Record *records;

    scanf("%d", &n);

    records = (struct Record *)malloc(n * sizeof(struct Record));
    if (records == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        scanf("%s %s %ld %ld", records[i].id, records[i].name, &records[i].salary, &records[i].sales);
    }
    
    char search_id[10];
    struct Record found_record;
    
    scanf("%s", search_id);
    
    if (find_record(records, n, search_id, &found_record)) {
        display_record(&found_record);
    } else {
        printf("ID not found !!!\n");
    }

    free(records);
    
    return 0;
}
