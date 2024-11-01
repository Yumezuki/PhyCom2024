#include <stdio.h>
#include <stdlib.h>

// โครงสร้าง DataNode
typedef struct DataNode {
    int data;
    struct DataNode* next;
} DataNode;

// โครงสร้าง SinglyLinkedList
typedef struct SinglyLinkedList {
    unsigned int count;
    DataNode* head;
} SinglyLinkedList;

// ฟังก์ชันสำหรับสร้างโหนดใหม่
DataNode* createDataNode(int data) {
    DataNode* newNode = (DataNode*)malloc(sizeof(DataNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ฟังก์ชันสำหรับสร้างลิสต์ใหม่
SinglyLinkedList* createSinglyLinkedList() {
    SinglyLinkedList* newList = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    if (newList == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newList->count = 0;
    newList->head = NULL;
    return newList;
}

// ฟังก์ชันสำหรับเพิ่มข้อมูลเข้าไปในตำแหน่งที่ระบุ
void insert_at_position(SinglyLinkedList* list, int data, int position) {
    if (position < 0 || position > list->count) {
        printf("Invalid position.\n");
        return;
    }

    DataNode* newNode = createDataNode(data);
    if (newNode == NULL) {
        return;
    }

    if (position == 0) {
        // เพิ่มที่ตำแหน่งแรก (head)
        newNode->next = list->head;
        list->head = newNode;
    } else {
        DataNode* current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    list->count++;
}

// ฟังก์ชันสำหรับแสดงข้อมูลในลิสต์
void traverse(SinglyLinkedList* list) {
    DataNode* pointer = list->head;
    if (pointer == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (pointer != NULL) {
        printf("%d", pointer->data);
        pointer = pointer->next;
        if (pointer != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main() {
    SinglyLinkedList* mylist = createSinglyLinkedList();
    int n, value, position;

    // รับจำนวนข้อมูลที่จะใส่เข้าไปในลิสต์
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // รับข้อมูลและเพิ่มลงในลิสต์
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insert_at_position(mylist, value, i);  // เพิ่มที่ตำแหน่งท้ายลิสต์
    }

    // แสดงข้อมูลก่อนทำการเพิ่มที่ตำแหน่งระบุตำแหน่ง
    printf("Initial List: ");
    traverse(mylist);

    // รับตำแหน่งและข้อมูลที่จะเพิ่ม
    printf("Enter value to insert: ");
    scanf("%d", &value);
    printf("Enter position to insert at: ");
    scanf("%d", &position);

    // เพิ่มข้อมูลในตำแหน่งที่ระบุ
    insert_at_position(mylist, value, position);

    // แสดงข้อมูลหลังการเพิ่ม
    printf("Updated List: ");
    traverse(mylist);

    // Free memory for each node
    DataNode* current = mylist->head;
    while (current != NULL) {
        DataNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(mylist);

    return 0;
}
