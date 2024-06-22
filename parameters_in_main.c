#include<stdio.h>

int main(int argc, char* argv[]){

    printf("El numero de argumentos es: %i\n", argc);
    printf("El primer argumento es : %s\n", argv[0]);
    printf("El segundo argumento es: %s\n", argv[1]);

    return 0;
}