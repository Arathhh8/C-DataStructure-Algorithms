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
void printListNode(ListNode* head);

int main (void){

    ListNode* head = NULL;

    insertAtEnd(&head, 5);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 7);
    printListNode(head);
    deleteNode(&head, 6);
    printListNode(head);
    
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
    ListNode* current = *head;
    
    if(*head == NULL){
        *head = newNode;
        return;
    }

    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(ListNode** head,  int value){

    if (*head == NULL) {
        return;
    }

    ListNode* current = *head;
    ListNode* previous = NULL;

     // Si el nodo a eliminar es el primero
    if (current != NULL && current->value == value) {
        *head = current->next;
        free(current);
        return;
    }

    // Buscar el nodo a eliminar
    while (current != NULL && current->value != value) {
        previous = current;
        current = current->next;
    }

    // Si no se encuentra el valor
    if (current == NULL) {
        printf("Node was not found\n");
        return;
    }

    // Eliminar el nodo
    previous->next = current->next;
    free(current);
    
}

void printListNode(ListNode* head){

    ListNode* p = head;

    while(p != NULL){
        printf("\t%d->",p->value);
        p = p->next;
    }
    printf("\n");
}



// 10 -> 12 -> 15 -> 46 -> NULL; este es el objetivo del linked list singly