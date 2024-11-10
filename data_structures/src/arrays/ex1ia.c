#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function prototypes
void inputArraySize(int *size);
void populateArray(int size, int arr[]);
int calculateSum(int size, int arr[]);
void findMaxMin(int size, int arr[], int *max, int *min);
double computeAverage(int size, int arr[]);
void reverseArray(int size, int arr[]);

int main() {
    int size;

    // Input the size of the array
    inputArraySize(&size);

    // Allocate memory for the array
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Populate the array with user input
    populateArray(size, array);

    // Calculate and print the sum of the array elements
    int sum = calculateSum(size, array);
    printf("Sum of array elements: %d\n", sum);

    // Find and print the maximum and minimum elements in the array
    int max, min;
    findMaxMin(size, array, &max, &min);
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    // Calculate and print the average of the array elements
    double average = computeAverage(size, array);
    printf("Average of array elements: %.2f\n", average);

    // Reverse and print the array
    reverseArray(size, array);

    // Free allocated memory
    free(array);

    return 0;
}

// Function to input the size of the array
void inputArraySize(int *size) {
    printf("Enter the number of elements: ");
    scanf("%d", size);
}

// Function to populate the array with user input
void populateArray(int size, int arr[]) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Function to calculate the sum of the array elements
int calculateSum(int size, int arr[]) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to find the maximum and minimum elements in the array
void findMaxMin(int size, int arr[], int *max, int *min) {
    *max = INT_MIN;
    *min = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

// Function to compute the average of the array elements
double computeAverage(int size, int arr[]) {
    int sum = calculateSum(size, arr);
    return (double)sum / size;
}

// Function to reverse the array and print it
void reverseArray(int size, int arr[]) {
    printf("Reversed array: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", arr[i]);
        if (i > 0) {
            printf(", ");
        }
    }
    printf("\n");
}
