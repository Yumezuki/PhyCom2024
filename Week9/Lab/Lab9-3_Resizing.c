#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort (ascending order)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int *arr = NULL;        // Pointer to the dynamic array
    int size = 0;           // Current number of elements in the array
    int capacity = 10;      // Initial capacity of the array
    int num;                // Variable to store user input

    // Allocate initial memory for the array
    arr = (int *) malloc(capacity * sizeof(int));

    // Input loop: Read integers until the user enters -1
    while (1) {
        scanf("%d", &num);     // Read an integer from the user
        if (num == -1)          // Stop if the user enters -1
            break;

        // Resize the array if it's full
        if (size >= capacity) {
            capacity *= 2;                                          // Double the capacity
            int *temp = (int *) realloc(arr, capacity * sizeof(int)); // Reallocate memory for the array with the new capacity
            if (temp == NULL) {                                     // Check if realloc failed
                perror("Realloc failed");
                free(arr);                                          // Free the original array
                exit(EXIT_FAILURE);
            }
            arr = temp;                                            // Update 'arr' to point to the newly allocated memory
        }

        // Add the new element to the array using pointer arithmetic
        *(arr + size) = num;
        size++;
    }

    // Print the original array
    printf("You entered: ");
    int *ptr = arr;                 // Initialize a pointer to traverse the array
    int i = 0;
    while (i < size) {              // Loop until the end of the array
        printf("%d ", *(ptr + i));  // Print the current element
        i++;
    }
    printf("\n");

    // Sort the array using qsort
    qsort(arr, size, sizeof(int), compare);

    // Print the sorted array
    printf("Sorted array: ");
    ptr = arr;                     // Reset the pointer to the beginning of the array
    i = 0;
    while (i < size) {            // Loop until the end of the array
        printf("%d ", *(ptr + i));  // Print the current element
        i++;
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);
    return 0;
}
