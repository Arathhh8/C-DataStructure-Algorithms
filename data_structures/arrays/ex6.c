/*Ejercicio: Manipulación de Cadenas de Caracteres

Escribe un programa en C que realice las siguientes tareas:

Solicitar al usuario que ingrese una cadena de caracteres (máximo 100 caracteres).
Convertir todos los caracteres de la cadena a mayúsculas.
Contar el número de vocales (a, e, i, o, u) en la cadena.
Imprimir la cadena convertida a mayúsculas y el número de vocales encontradas.
Requisitos adicionales:

Utiliza funciones para separar la lógica del programa. Al menos, debes tener las siguientes funciones:
Una función para ingresar la cadena.
Una función para convertir la cadena a mayúsculas.
Una función para contar las vocales.
Una función para imprimir los resultados.
Entrada de ejemplo:

yaml
Copy code
Ingrese una cadena: Hello World
Salida de ejemplo:

mathematica
Copy code
Cadena en mayúsculas: HELLO WORLD
Número de vocales: 3 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Function prototypes
void inputString(char **string);
void lowerToCapital(char *string);
void vowelsCounter(char *string, int *counter);
void printResults(char *string, int counter);

#define MAX_LENGTH 100

int main(void){

    char *user_word = (char *)malloc(MAX_LENGTH * sizeof(char));
    if (user_word == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int *vowelsCount = (int *)malloc(sizeof(int));
    if (vowelsCount == NULL) {
        printf("Memory allocation failed\n");
        free(user_word);
        return 1;
    }

    *vowelsCount = 0;

    inputString(&user_word);

    lowerToCapital(user_word);

    vowelsCounter(user_word, vowelsCount);

    printResults(user_word, *vowelsCount);

    // Free allocated memory
    free(user_word);
    free(vowelsCount);

    return 0;
}

void inputString(char **string){

    printf("Enter the string: ");
    fgets(*string, MAX_LENGTH, stdin); // read the string inlcudding spaces 
}

void lowerToCapital(char *string){

    size_t len = strlen(string) - 1;

    for(int i = 0; i < len; i++){
        if(string[i] > 96 && string[i] < 123){
            string[i] = string[i] - 32;
        }
    }
}

void vowelsCounter(char *string, int *counter){

    size_t len = strlen(string) - 1;

    for(int i = 0; i < len; i++){
        if(string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U'){
            *counter = *counter + 1;
        }
    }
}

void printResults(char *string, int counter){
    printf("Uppercase string: %s", string);
    printf("Number of vowels: %d\n", counter);
    
}