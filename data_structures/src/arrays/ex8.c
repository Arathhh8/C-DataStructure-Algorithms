/* : Análisis de Palabras en una Frase
Descripción:

Escribe un programa en C que haga lo siguiente:

Solicite al usuario que introduzca una frase (una cadena de caracteres).
Almacene cada palabra de la frase en un array de punteros a cadenas (un array de strings).
Calcule la longitud de cada palabra y almacene estos valores en un array de enteros.
Imprima cada palabra junto con su longitud.
Imprima la palabra más larga y la palabra más corta en la frase.
Requisitos:

Usa memoria dinámica para almacenar las palabras.
Utiliza las funciones strcpy y strcmp donde sea apropiado.
Ejemplo de Entrada:


Ingrese una frase: "Esta es una frase de ejemplo"
Ejemplo de Salida:

Palabra 1: Esta, Longitud: 4
Palabra 2: es, Longitud: 2
Palabra 3: una, Longitud: 3
Palabra 4: frase, Longitud: 5
Palabra 5: de, Longitud: 2
Palabra 6: ejemplo, Longitud: 7

Palabra más larga: ejemplo
Palabra más corta: es
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LENGTH 100

// Function prototypes
void inputString(char *array);
void splitPhraseIntoWords(char *array, char **individual_string, int *elements);
void printMaxMin(char **individual_string, char *longer, char *smaller, int *elements);

int main(void){

    
    char user_string[MAX_LENGTH];
    char longer_string[MAX_LENGTH];
    char smaller_string[MAX_LENGTH];
    int elements = 0;

    // Allocate memory for individual strings
    char **individual_strings =  (char **)malloc(MAX_LENGTH * sizeof(char));

    if (user_string == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for(int i = 0; i < MAX_LENGTH; i ++){
        individual_strings[i] = (char *)malloc(100 * sizeof(char));   // Assuming max length of string is 100
        if(individual_strings[i] == NULL){
            printf("Memory allocation failed\n");
            return 1;
        }
    }

    // Input strings by user
    inputString(user_string);

    // Split the phrase in words
    splitPhraseIntoWords(user_string, individual_strings, &elements);

    // Print the larger and shorter words in the phrase
    printMaxMin(individual_strings, longer_string, smaller_string, &elements);

    // Free allocated memory
    for (int i = 0; i < MAX_LENGTH; i++) {
        free(individual_strings[i]);
    }
    free(individual_strings);

    return 0;
}

void inputString(char *array){

    printf("Enter a phrase: ");
    fgets(array, MAX_LENGTH, stdin); // read the string inlcudding spaces
    array[strcspn(array, "\n")] = '\0'; // remove the newline character at the end
}

void splitPhraseIntoWords(char *array, char **individual_string, int *elements){
    
    *elements = 0;
    char delimiter[] = " ";
    char *token = strtok(array, delimiter);


    while(token != NULL){

        int len = strlen(token);

        printf("Palabra %d: %s, Longitud: %d\n", *elements, token, len);
        strcpy(individual_string[*elements], token);
        token = strtok(NULL, delimiter);
        (*elements)++;
    }
    
    printf("Num of elements: %d\n", *elements);
}

void printMaxMin(char **individual_string, char *longer, char *smaller, int *elements){

    int max_length = 0;
    int min_length = MAX_LENGTH;

    for(int i = 0; i < *elements; i++) {
        int len = strlen(individual_string[i]);
        if(len > max_length) {
            strcpy(longer, individual_string[i]);
            max_length = len;
        }
        if(len < min_length) {
            strcpy(smaller, individual_string[i]);
            min_length = len;
        }
    }

    printf("Longest: %s\n", longer);
    printf("Shortest: %s\n", smaller);
}