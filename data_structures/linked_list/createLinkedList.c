/* 
    En este programa se creara un linked list, la cual permitira:
    -Crear un nodo
    -Anadir un nodo al final de la lista
    -Imprimir la lista completa

*/


/* Una Linked List es una estructura de datos lineal, compuesta de nodos, en donde cada nodo contiene:
    - Valor: uno o varios valores asociados al nodo
    - Puntero: contiene un puntero o una referencia al siguiente nodo

    La linked list tiene la caracteristica de los nodos no se encuentrar en direcciones de memoria contiguas, como en el caso del array, sino que las direcciones 
    de memoria se encuetran dispersas, pero pudiendo acceder a cada una de ellas por la referencia que se tiene del siguiente nodo, debido a esto existen distintos tipos de linked list, singly, doubly, circular

    Singly: este es el caso mas basico en donde un nodo contiene un valor y una referencia al siguiente nodo
    Doubly: contiene un valor y un puntero al siguiente nodo, asi como mantiene un puntero al nodo anterior
    Circular: contiene un valor y un nodo al siguiente nodo, en donde el ultimo nodo apunta al primer nodo, formando un ciclo
*/

#include<stdio.h>
#include<stdlib.h>

// Estructura del nodo principal
typedef struct ListNode{

    int value;
    struct ListNode* next;

}ListNode;


// Funcion para crear un nodo
ListNode* createNode(int val);

// Funcion para agregar un nodo al final de la lista
void createAtInit(ListNode** head, int val);

// Funcion para agregar un nodo al final de la lista
void createAtEnd(ListNode** head, int val);

// Funcion para eliminar un nodo por valor
void deleteNodeByValue(ListNode** head, int val);

// Imprir la lista completa
void printList(ListNode* head);

int main(void){

    ListNode* head = NULL;

    createAtEnd(&head, 1);
    createAtEnd(&head, 2);
    createAtEnd(&head, 3);
    deleteNodeByValue(&head, 2);

    printList(head);

    createAtEnd(&head, 4);
    
    printList(head);

    createAtInit(&head, 5);
    createAtInit(&head, 6);
    createAtInit(&head, 7);

    printList(head);


    return 0;
}

ListNode* createNode(int val){

    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

    if(newNode == NULL){
        printf("Fallo en la alocacion de memoria");
        return NULL;
    }

    newNode->value = val;
    newNode->next = NULL;

    return newNode;

}

void createAtInit(ListNode** head, int val){
    ListNode* newNode = createNode(val);
    ListNode* current = *head;

    // si la lista esta vacia, agregar el primer elemento
    if(*head == NULL){
        *head = newNode;
        return;
    }

    // si la lista no esta vacia, agregar un elemento al inicio
    newNode->next = *head;

    *head = newNode;

}

void createAtEnd(ListNode** head, int val){

    ListNode* newNode = createNode(val);
    ListNode* current = *head;

    // Primero se verifica si la lista esta vacia y en caso afirmativo se crea el primer nodo 
    if(*head == NULL){
        *head = newNode;
        return;
    }

    // 1 -> 2 -> 3 -> 4 -> NULL
    // Si la lista no esta vacia, entonces se recorre la lista hasta el nodo final
    while (current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
}
// 1 -> 2 -> 3 -> 4 -> NULL
// eliminar 3: 
void deleteNodeByValue(ListNode** head, int val){

    ListNode* current = *head;
    ListNode* previous = NULL;

    // si la lista esta vacia, no existe nodo a eliminar
    if(*head == NULL){
        printf("Lista vacia");
        return;
    }

    // Si el elemento a eliminares el primero
    if(current->value == val && current != NULL){
        *head = current->next;
        printf("Elemento eliminado\n");
        free(current);
        return;
    }

    // Buscar el nodo a eliminar
    while (current != NULL && current->value != val) {
        previous = current;
        current = current->next;
    }

    // Si no se encuentra el valor
    if (current == NULL) {
        printf("Node was not found\n");
        return;
    }

    previous->next = current->next;
    free(current);
}

void printList(ListNode* head){

    // Verificar si la lista esta vacia
    if(head == NULL){
        printf("La lista esta vacia");
        return;
    }

    ListNode* current = head;

    // Si la lista no esta vacia, se imprimer los valores
    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }

    printf("NULL\n");
    
}