#include<stdio.h>

int main(int argc, char* argv[]){

    printf("Numero de argumentos: %i\n", argc);
    printf("Argumento 1: %s\n", argv[0]);
    printf("Argumento 2: %s\n", argv[1]);
    printf("Argumento 3: %s'n", argv[2]);
    
    return 0;
}