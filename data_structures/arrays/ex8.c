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

arduino
Copy code
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

#define MAX_LENGTH 100

// Function prototypes
void inputString(char *array);

int main(void){

    char user_string[MAX_LENGTH];

    inputString(user_string);

    printf("String: %s", user_string);


    return 0;
}

void inputString(char *array){

    printf("Enter a phrase: ");
    fgets(array, MAX_LENGTH, stdin); // read the string inlcudding spaces
    printf("Size: %d\n", strlen(array));
}