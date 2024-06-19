#include <stdio.h>
#include <ctype.h> // Para usar funciones como tolower()

int main() {
    char cadena[100];
    int contador[5] = {0}; // Un arreglo para contar las vocales a, e, i, o, u
    
    // Pedir al usuario que ingrese una cadena
    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin);
    
    // Recorrer la cadena caracter por caracter
    for (int i = 0; cadena[i] != '\0'; i++) {
        char caracter = tolower(cadena[i]); // Convertir a minúscula (si es letra)
        
        // Incrementar el contador correspondiente según la vocal encontrada
        switch(caracter) {
            case 'a':
                contador[0]++;
                break;
            case 'e':
                contador[1]++;
                break;
            case 'i':
                contador[2]++;
                break;
            case 'o':
                contador[3]++;
                break;
            case 'u':
                contador[4]++;
                break;
            default:
                break;
        }
    }
    
    // Imprimir los resultados
    printf("Contador de vocales:\n");
    printf("- a: %d\n", contador[0]);
    printf("- e: %d\n", contador[1]);
    printf("- i: %d\n", contador[2]);
    printf("- o: %d\n", contador[3]);
    printf("- u: %d\n", contador[4]);
    
    return 0;
}
