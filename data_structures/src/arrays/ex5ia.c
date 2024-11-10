#include <stdio.h>
#include <ctype.h> // Librería para usar la función tolower()
#include <string.h>

void inputString(char *string);
void countVowels(const char *string, int *a, int *e, int *i, int *o, int *u);
void printNumVowels(int a, int e, int i, int o, int u);

int main(void) {
    char string[100]; // Tamaño suficiente para la entrada del usuario
    int a = 0, e = 0, i = 0, o = 0, u = 0;

    inputString(string);
    countVowels(string, &a, &e, &i, &o, &u);
    printNumVowels(a, e, i, o, u);

    return 0;
}

void inputString(char *string) {
    printf("Enter a word or phrase: ");
    fgets(string, 100, stdin); // Lee la cadena incluyendo espacios
    // Elimina el salto de línea al final de la cadena si existe
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}

void countVowels(const char *string, int *a, int *e, int *i, int *o, int *u) {
    // Itera sobre cada carácter de la cadena
    for (int j = 0; string[j] != '\0'; j++) {
        char ch = tolower(string[j]); // Convierte el carácter a minúscula
        switch (ch) {
            case 'a':
                (*a)++;
                break;
            case 'e':
                (*e)++;
                break;
            case 'i':
                (*i)++;
                break;
            case 'o':
                (*o)++;
                break;
            case 'u':
                (*u)++;
                break;
            default:
                break; // No hace nada si no es una vocal
        }
    }
}

void printNumVowels(int a, int e, int i, int o, int u) {
    printf("Number of vowels:\n");
    printf("A: %d\n", a);
    printf("E: %d\n", e);
    printf("I: %d\n", i);
    printf("O: %d\n", o);
    printf("U: %d\n", u);
}
