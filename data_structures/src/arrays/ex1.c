/* Escribe un programa en C que haga lo siguiente:

Entrada:

Solicite al usuario el número de elementos de un array.
Solicite al usuario que ingrese los elementos del array (números enteros).
Operaciones:

Calcule y muestre la suma de todos los elementos del array.
Encuentre y muestre el elemento mayor y el menor del array.
Calcule y muestre el promedio de los elementos del array.
Invierta los elementos del array y muestre el array invertido.
Especificaciones:
Debes utilizar un array de tamaño dinámico para almacenar los elementos ingresados por el usuario.
Implementa funciones separadas para cada operación (suma, encontrar el mayor y el menor, calcular el promedio, invertir el array). 
*/


#include<stdio.h>
#include<stdlib.h>

int get_element_nums();
void fill_array(int n, int *array);
int sum_elements(int element_nums, int *array);
void find_max_and_min(int element_nums, int *array);
void array_average(int element_nums, int *array);
void array_invert(int element_nums, int *array);

//int user_array[100]; 

int main(void){

    int elements_in_array; // number of element in the array

    elements_in_array = get_element_nums();

    // Allocate memory for the array dynamically
    int *user_array = (int *)malloc(elements_in_array * sizeof(int));

    if (user_array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    fill_array(elements_in_array, user_array);

    sum_elements(elements_in_array, user_array);

    find_max_and_min(elements_in_array, user_array);

    array_average(elements_in_array, user_array);

    array_invert(elements_in_array, user_array);

    free(user_array);

    return 0;
}


 // This function returns the number elements given by the user

int get_element_nums(){
    
    int element_num = 0;

    printf("Type number element of the array: ");
    scanf("%d", &element_num);
    printf("\n");

    return element_num;

}


// This function fills the array

void fill_array(int n, int *array){

    printf("Please, fill the array\n");

    for(int i = 0; i < n; i++){
        printf("Type a number for position %d: ", i);
        scanf("%d", &array[i]); // NEW TECNIC
    }
}


// This function makes the sum of all elements in the array

int sum_elements(int element_nums, int *array){

    int result = 0; 

    for(int i = 0; i <  element_nums; i++){
        result += array[i];
    }

    printf("Sum: %d\n",result);

    return result;
}


// This function find the max and min value in the array

void find_max_and_min(int element_nums, int *array){
    int max = 0;
    int min = 0x7FFFFFFE;

    for(int i = 0; i < element_nums; i++){
        
       if(max < array[i]){
        max = array[i];
       }

       if(min > array[i]){
        min = array[i];
       }
    }

    printf("Max: %d\n",max);
    printf("Min: %d\n",min);
}

// This function calculates the average of the array

void array_average(int element_nums, int *array){

    float average = 0;

    average = (float)sum_elements(element_nums, array) / (float)element_nums;

    printf("Average: %.2f\n", average);
}

// This function invert all elements in the array

void array_invert(int element_nums, int *array){
    
    int array_inverted[element_nums];

    for(int i = element_nums; i > 0; i--){
        array_inverted[element_nums - i] = array[i-1];
    }

    // printing the inverted array

    printf("Inverted array: ");
    for(int i = 0; i < element_nums; i++){
        
        printf("%d", array[i]);
        if (i < element_nums-1) {
            printf(",");
        }
    }
}
