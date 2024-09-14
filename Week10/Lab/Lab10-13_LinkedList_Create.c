#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DataNode {
  char* data;
  struct DataNode* next;
} DataNode;

DataNode* createDataNode(char* data);

int main() {
  char data[101];
  scanf("%[^\n]s", data);

  // Create a new DataNode
  DataNode* pNew = createDataNode(data);

  // Print the data and next pointer
  printf("%s\n", pNew->data);
  printf("%p\n", (void*)pNew->next);

  // Free allocated memory for data
  free(pNew->data);
  free(pNew);
  return 0;
}

// Create a new DataNode
DataNode* createDataNode(char* data) {
  // Allocate memory for the node
  DataNode* newNode = (DataNode*)malloc(sizeof(DataNode));

  // Allocate memory for the string and copy the data
  newNode->data = (char*)malloc(strlen(data) + 1);
  strcpy(newNode->data, data);

  newNode->next = NULL;
  return newNode;
}