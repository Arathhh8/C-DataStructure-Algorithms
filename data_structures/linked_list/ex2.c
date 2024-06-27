/* Ejercicio: Implementar una Linked List Básica
Objetivo
Implementar una singly linked list en C y realizar las siguientes operaciones:

Insertar un nodo al final de la lista.
Eliminar un nodo con un valor específico.
Imprimir todos los elementos de la lista.

Paso 1: Definir la Estructura del Nodo
Define la estructura ListNode para representar un nodo de la linked list.

Paso 2: Crear Funciones para las Operaciones

Crear un Nodo:
Función createNode para reservar memoria y crear un nuevo nodo.

Insertar al Final:
Función insertAtEnd para insertar un nuevo nodo al final de la lista.

Eliminar un Nodo:
Función deleteNode para eliminar el primer nodo que contiene un valor específico.

Imprimir la Lista:
Función printList para imprimir todos los elementos de la lista.

Instrucciones
Crear y Compilar el Código:

Copia y pega el código en un archivo .c.
Compílalo usando gcc (por ejemplo, gcc -o linkedlist linkedlist.c).
Ejecútalo para ver cómo funciona la linked list.
Entender el Flujo:

Inserta nodos en la lista.
Imprime la lista para verificar la inserción.
Elimina un nodo específico.
Imprime la lista nuevamente para verificar la eliminación.
Practicar y Experimentar:

Añade más funciones, como insertar en una posición específica o buscar un nodo por valor.
Manipula la lista para fortalecer tu comprensión de cómo funcionan las linked lists.
Este ejercicio te ayudará a entender los conceptos básicos de linked lists y a familiarizarte con las operaciones comunes que se pueden realizar en ellas.
*/

#include<stdio.h>
#include<stdlib.h>


// Main struct

typedef struct ListNode{
    int value;
    struct ListNode* next;
}ListNode;


// Function prototypes
ListNode* createNode(int value);
void insertAtEnd(ListNode** head, int value);
void deleteNode(ListNode** head,  int value);

int main (void){

    createNode();
    createNode();
    
    return 0;
}

ListNode* createNode(int value){

    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if(newNode == NULL){
        printf("Memory allacation failed");
        return NULL;
    }

    newNode->value = value;
    newNode->next = NULL;
    
    return newNode;
}

void insertAtEnd(ListNode** head, int value){

    ListNode* newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    ListNode* current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
}



// 10 -> 12 -> 15 -> 46 -> NULL; este es el objetivo del linked list singly