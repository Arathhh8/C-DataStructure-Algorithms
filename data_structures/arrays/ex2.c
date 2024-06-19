/* Escribe un programa en C que haga lo siguiente:

Pide al usuario que ingrese el tamaño de dos arrays de enteros (array A y array B).
Llena ambos arrays con números enteros proporcionados por el usuario.
Crea un tercer array (array C) que contenga la suma de los elementos correspondientes de los arrays A y B.
Imprime el contenido de los tres arrays (A, B, y C).
Especificaciones:
Cada elemento en el array C debe ser la suma del elemento correspondiente en el array A y el array B (es decir, C[i] = A[i] + B[i]).
El programa debe manejar correctamente el caso en que los arrays A y B tienen el mismo tamaño. */

#include<stdio.h>
#include<stdlib.h>

// Function prototypes
void inputArraySize(int *size);
void populateArrays(int size, int *arrayA, int *arrayB);
void sumArrays(int size, int *arrayA, int *arrayB, int *arrayC);
void printArray(int size, int *array, char letter);

int main(void){

    int size;

    // Get the size of the array
    inputArraySize(&size);

    // Allocate memory for the arrays
    int *arrayA = (int *)malloc(size * sizeof(int));
    int *arrayB = (int *)malloc(size * sizeof(int));
    int *arrayC = (int *)malloc(size * sizeof(int));

    if (arrayA == NULL || arrayB == NULL || arrayC == NULL) {
        printf("Memory allocation failed\n");
        free(arrayA);
        free(arrayB);
        free(arrayC);
        return 1;
    }

    printf("Size of arrays: %d\n", size);

    // Populate arrayA and arrayB 
    populateArrays(size, arrayA, arrayB);

    // Make sum of arrayA[i] + arrayB[i]
    sumArrays(size, arrayA, arrayB, arrayC);

    // Print arrays
    printArray(size, arrayA, 'A');
    printArray(size, arrayB, 'B');
    printArray(size, arrayC, 'C');

    // Free allocated memory
    free(arrayA);
    free(arrayB);
    free(arrayC);
    
    return 0;
}


void inputArraySize(int *size){

    printf("Enter size for arrayA: ");
    scanf("%d", size);

}


void populateArrays(int size, int *arrayA, int *arrayB){
    
    printf("***** Adding data to arrayA *****\n");
    for(int i = 0; i < size; i++){
        printf("Enter position %d: ", i+1);
        scanf("%d", &arrayA[i]);
    }

    printf("***** Adding data to arrayB *****\n");
    for(int i = 0; i < size; i++){
        printf("Enter position %d: ", i+1);
        scanf("%d", &arrayB[i]);
    }
}

void sumArrays(int size, int *arrayA, int *arrayB, int *arrayC){

    for(int i = 0; i < size; i++){
        arrayC[i] = arrayA[i] + arrayB[i];
    }
}

void printArray(int size, int *array, char letter){

    printf("array %c: ", letter);
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

}
