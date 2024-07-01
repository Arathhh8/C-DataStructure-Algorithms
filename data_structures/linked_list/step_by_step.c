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

// 5. Imprimir la lista
// Implementa una funcion para imprimir todos los nodos de la lista
void printList(ListNode* head);



int main() {
    ListNode* head = NULL;

    // Inserta nodos
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    // Imprime la lista
    printf("Lista despues de insertar 3 nodos: ");
    printList(head);

    // Elimina un nodo
    deleteNode(&head, 2);

    // Imprime la lista después de eliminar
    printf("Lista despues de eliminar el nodo con valor 2: ");
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
        return NULL;
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
        return;
    }

    current = *head;

    while (current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
}

void deleteNode(ListNode** head, int value){

    // Si la lista esta vacia, no realizar ninguna operacion
    if (*head == NULL) {
        printf("La lista esta vacia");
        return;
    }

    // creamos un puntero que mantenta el nodo actual y otro para mantener un enlace al nodo previo
    ListNode* current = *head;
    ListNode* previous = NULL;

    // Se maneja el caso en el que el nodo a eliminar sea el primero
    if(current != NULL && current->value == value){
        *head = current->next;
        free(current);
        return;
    }

    // Se recorre la lista para encontrar el nodo con el valor dado
    while(current != NULL && current->value != value){
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
    printf("Nodo con valor %d eliminado.\n", value);
}


void printList(ListNode* head){

    ListNode* current = head;

    // Si la lista esta vacia, no realizar ninguna operacion
    if (head == NULL) {
        return;
    }

    while (current != NULL){
        printf("%d -> ", current->value);
        current = current->next;
    }

    printf("NULL");
    printf("\n");

}