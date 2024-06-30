/* Proyecto para crear paso a paso una lista enlazada */

#include<stdio.h>
#include<stdlib.h>

// 1. Define la estructura del nodo

typedef struct ListNode{
    int value;
    struct ListNode* next;
}ListNode;


// 2. Crear un Nodo
// Implementa una función para crear un nuevo nodo. Esta función tomará un valor y devolverá un puntero al nuevo nodo.
ListNode* createNode(int value);

// 3. Insertar un Nodo al Final
// Implementa una función para insertar un nodo al final de la lista.
void insertAtEnd(ListNode** head, int value);

// 4. Borrar un Nodo por Valor
// Implementa una función para borrar un nodo que contiene un valor específico.
void deleteNode(ListNode** head, int value);



int main() {
    ListNode* head = NULL;

    // Inserta nodos
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    // Imprime la lista
    printf("Lista después de insertar 3 nodos: ");
    printList(head);

    // Elimina un nodo
    deleteNode(&head, 2);

    // Imprime la lista después de eliminar
    printf("Lista después de eliminar el nodo con valor 2: ");
    printList(head);

    // Libera la memoria
    deleteNode(&head, 1);
    deleteNode(&head, 3);

    return 0;
}

ListNode* createNode(int value){

    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode)); // Reserva memoria para el nuevo nodo
    if(newNode == NULL){
        printf("Memory allocation failed");
        return;
    }

    newNode->value = value; // asigno el valor al nuevo nodo
    newNode->next = NULL;   // inicializa el puntero 'next' a null

    return newNode;
}

void insertAtEnd(ListNode** head, int value){
    ListNode* newNode = createNode(value);
    ListNode* current;

    // Si la lista está vacía (*head es NULL), asigna el nuevo nodo a *head.
    if(*head == NULL){
        *head = newNode;
    }

    current = *head;

    while (current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
}

void deleteNode(ListNode** head, int value){

    if (*head == NULL) {
        return;
    }

    ListNode* current = *head;
    ListNode* previous = NULL;

    if(current != NULL && current->value == value){
        *head = current->next;
        free(current);
        return;
    }

    while(current != NULL && current->value != value){
        previous = current;
        current = current->next;
    }

    
    
}