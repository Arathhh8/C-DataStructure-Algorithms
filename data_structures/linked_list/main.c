/*
Ejercicio: Implementación básica de una lista enlazada

Definición de la estructura:
Define una estructura Nodo que contenga un entero y un puntero al siguiente nodo.
Función para crear un nuevo nodo:
Implementa una función que cree un nuevo nodo con un valor entero dado y que devuelva un puntero a este nodo.
Función para agregar un nodo al principio de la lista:
Implementa una función que tome un valor entero y un puntero al primer nodo de la lista, y agregue un nuevo nodo al principio de la lista.
Función para imprimir la lista:
Implementa una función que imprima todos los valores de los nodos de la lista enlazada desde el primero hasta el último.
Tareas:

Define la estructura Nodo.
Escribe una función para crear un nuevo nodo.
Escribe una función para agregar un nodo al principio de la lista.
Escribe una función para imprimir todos los nodos de la lista.
Ejemplo de uso:

Crear una lista enlazada vacía.
Agregar algunos nodos al principio de la lista con valores 10, 20 y 30.
Imprimir la lista resultante.
*/
#include<stdio.h>
#include<stdlib.h>
#include"linked_list_functions.h"

#define MAX_NUM_NODES 5

int main(void){

    ListNode* head = NULL;

    for(int i = 1; i < MAX_NUM_NODES; i++)
    {
        createNodeAtEnd(&head, i);
    }

    printList(head);

    return 0;
}