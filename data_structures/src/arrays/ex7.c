/* Ejercicio: Ordenar una lista de cadenas alfabéticamente
Descripción del problema:
Escribe un programa en C que tome una lista de cadenas de texto (palabras) ingresadas por el usuario, las almacene en un array de cadenas, y luego las ordene alfabéticamente. Utiliza las funciones strcpy y strcmp para realizar la ordenación.

Requisitos:

El programa debe permitir al usuario ingresar el número de palabras que desea ordenar.
El programa debe permitir al usuario ingresar cada una de las palabras.
El programa debe almacenar estas palabras en un array de cadenas.
El programa debe ordenar las palabras alfabéticamente.
El programa debe mostrar las palabras ordenadas alfabéticamente.
Entradas:

Un entero n que representa el número de palabras.
n palabras de longitud variable (máximo 100 caracteres cada una).
Salidas:

Las palabras ordenadas alfabéticamente.
Ejemplo de uso:
Entrada:

Copy code
Ingrese el número de palabras: 3
Ingrese la palabra 1: manzana
Ingrese la palabra 2: pera
Ingrese la palabra 3: banana
Salida:

Palabras ordenadas alfabéticamente:
banana
manzana
pera */

#include<stdio.h>   // biblioteca estandar para entrada / salida de datos 
#include<string.h>  // biblioteca estandar para manejo de stings strlen, strcpy, strcmp
#include<stdlib.h>  // biblioteca estandar para utilidades generales, manejo dinamico de memoria malloc, calloc, realloc, free

void inputSizeString(int *elements);
void inputStrings(int *elements, char **string);
void sortStrings(int *elements, char **string);

int main(void){

    int num_elements = 0;

    inputSizeString(&num_elements); // Get the number of elements 

    char **user_string = (char **)malloc(num_elements * sizeof(char)); // Allocate memory for an array of pointers to strings
    if (user_string == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for(int i = 0; i < num_elements; i ++){
        user_string[i] = (char *)malloc(100 * sizeof(char));   // Assuming max length of string is 100
        if(user_string[i] == NULL){
            printf("Memory allocation failed\n");
            return 1;
        }
    }

    inputStrings(&num_elements, user_string); // Populating strings 

    for(int i = 0; i < num_elements; i++){

        printf("%s\n", user_string[i]);
    }

    sortStrings(&num_elements, user_string);

    // Free allocated memory
    for (int i = 0; i < num_elements; i++) {
        free(user_string[i]);
    }
    free(user_string);
    
    return 0;
}


// Function to get the number of elements given by the user
void inputSizeString(int *elements){

    printf("Enter the number of words: ");
    scanf("%d", elements);
}

// Function to populate the strings by the user
void inputStrings(int *elements, char **user_string){

    printf("elements: %d\n", *elements);

    for(int i = 0; i < *elements; i++){
        printf("Enter word %d: ", i+1);
        scanf("%s", user_string[i]);
    }
}

// Function to sort the elements, using bubble sort algorithm 
void sortStrings(int *elements, char **string){

    char temp[100];

    for(int i = 0; i < *elements; i++){
        for(int j = i + 1; j < *elements; j++){
            if(strcmp(string[i], string[j]) > 0){
                strcpy(temp, string[i]);
                strcpy(string[i], string[j]);
                strcpy(string[j], temp);
            }
        }    
    }

    for(int i = 0; i < *elements; i++){
        printf("Element %d: %s\n", i+1, string[i]);
        
    }
}