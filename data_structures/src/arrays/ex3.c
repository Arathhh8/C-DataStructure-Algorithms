#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void inputSizeArray(int *size);
void populateArray(int size, int *array);
void inputPositionsToRotate(int *positions);
void rotateToRight(int *array, int *arrayRotated, int size, int positions);
void printArray(int size, int *array, const char *message);

int main(void) {
    int size = 0;
    int positions_to_rotate = 0;

    inputSizeArray(&size);
    
    int *array = (int *)malloc(size * sizeof(int));
    int *arrayRotated = (int *)malloc(size * sizeof(int));

    if (array == NULL || arrayRotated == NULL) {
        printf("Memory allocation failed\n");
        free(array);
        free(arrayRotated);
        return 1;
    }

    populateArray(size, array);
    inputPositionsToRotate(&positions_to_rotate);
    rotateToRight(array, arrayRotated, size, positions_to_rotate);

    printArray(size, array, "Original array:");
    printArray(size, arrayRotated, "Rotated array:");

    free(array);
    free(arrayRotated);

    return 0;
}

void inputSizeArray(int *size) {
    printf("Enter size for the array: ");
    scanf("%d", size);
}

void populateArray(int size, int *array) {
    printf("******** Populating the array ********\n");
    for (int i = 0; i < size; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}

void inputPositionsToRotate(int *positions) {
    printf("Enter the number of positions to rotate: ");
    scanf("%d", positions);
}

void rotateToRight(int *array, int *arrayRotated, int size, int positions) {
    positions = positions % size; // Handle cases where positions > size
    for (int i = 0; i < size; i++) {
        arrayRotated[(i + positions) % size] = array[i];
    }
}

void printArray(int size, int *array, const char *message) {
    printf("%s ", message);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
