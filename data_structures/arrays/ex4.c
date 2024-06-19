/*Ejercicio Propuesto:
Problema: Implementar un programa en C que realice las siguientes operaciones con cadenas:

Leer un número n de cadenas del usuario.
Almacenar estas cadenas en un array de punteros a caracteres.
Ordenar las cadenas alfabéticamente.
Imprimir las cadenas ordenadas.
Requisitos:
Leer cadenas: Usa scanf para leer cadenas del usuario y almacénalas en un array de punteros.
Ordenar cadenas: Implementa un algoritmo de ordenación (como bubble sort) para ordenar las cadenas alfabéticamente.
Imprimir cadenas: Muestra las cadenas ordenadas en la consola.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// Function prototypes
void inputNumStrings(int *num);
void inputStrings(int count, char **array);
void sortStrings(int count, char **array);
void printStrings(int count, char **array);

int main(void){

    int num_of_strings;

    // Input the number of strings
    inputNumStrings(&num_of_strings);

    // Allocate memory for an array of pointers to strings
    char **array = (char **)malloc(num_of_strings * sizeof(char *));
    for(int i = 0; i < num_of_strings; i++){
        array[i] = (char *)malloc(100 * sizeof(char)); // assuming max length of string is 100
    }

    // Input the strings
    inputStrings(num_of_strings, array);

    // Sort the strings
    sortStrings(num_of_strings, array);

    // Print the sorted strings
    printStrings(num_of_strings, array);

    return 0;
}

void inputNumStrings(int *num){

    printf("Enter the number of the strings: ");
    scanf("%d", num);
}

void inputStrings(int count, char **array){
    printf("Input the strings:\n");
    for(int i = 0; i < count; i++){
        printf("String %d: ", i + 1);
        scanf("%s", array[i]);
    }
}

// Implement function to sort the strings alphabetically
void sortStrings(int count, char **array) {
    char temp[100];
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(array[i], array[j]) > 0) {
                // Swap array[i] and array[j]
                strcpy(temp, array[i]);
                strcpy(array[i], array[j]);
                strcpy(array[j], temp);
            }
        }
    }
}

void printStrings(int count, char **array) {
    printf("Sorted strings:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", array[i]);
    }
}