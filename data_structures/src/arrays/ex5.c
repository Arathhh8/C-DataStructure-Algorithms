/* Problema: Contador de vocales

Escribe un programa en C que solicite al usuario ingresar una cadena de caracteres (una frase o palabra). 
El programa debe contar y luego imprimir cuántas veces aparece cada vocal (a, e, i, o, u) en la cadena ingresada.
Ignora si las letras son mayúsculas o minúsculas y considera únicamente las vocales sin acentos.*/

#include<stdio.h>
#include<string.h>

#define MAX_LENGTH 100 // Tamaño máximo de la cadena

void inputString(char *string);
void vowelsCounter(char *string, int *a, int *e, int *i, int *o, int *u);
void printNumVowels(int a, int e, int i, int o, int u);

int main(void){

    char *string;
    int a = 0;
    int e = 0;
    int i = 0;
    int o = 0;
    int u = 0;

    inputString(string);

    vowelsCounter(string, &a, &e, &i, &o, &u);

    printNumVowels(a, e, i, o, u);

    return 0;
}

void inputString(char *string){

    printf("Enter the word: ");
    scanf("%s", string);
}

void vowelsCounter(char *string, int *a, int *e, int *i, int *o, int *u){

    char string2[] = "hola mundo";
    printf("%d\n", strlen(string));
    printf("%d\n", strlen(string2));

    for(int j = 0; j < strlen(string); j++){
        if( string[j] == 'a'){
            *a = *a + 1;
        }else if(string[j] == 'e'){
            *e = *e + 1;
        }else if(string[j] == 'i'){
            *i = *i + 1;
        }else if(string[j] == 'o'){
            *o = *o + 1;
        }else if(string[j] == 'u'){
            *u = *u + 1;
        }
    }
}

void printNumVowels(int a, int e, int i, int o, int u){
    printf("a: %d\n", a);
    printf("e: %d\n", e);
    printf("i: %d\n", i);
    printf("o: %d\n", o);
    printf("u: %d\n", u);
}