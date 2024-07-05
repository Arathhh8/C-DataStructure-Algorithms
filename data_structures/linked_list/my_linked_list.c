// Creando mi propia linked list

#include<stdio.h>
#include<stdlib.h>

// Estructura del nodo
typedef struct ListNode{

    int val;
    struct ListNode* next;

}ListNode;

// Prototipos de funciones
ListNode* createNode(int value);
void insertAtEnd(ListNode** head,int value);
void printList(ListNode* head);



int main(void){

    ListNode* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);

    printList(head);

    printf("Lista insertando 2 nodos mas\n");

    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    printList(head);
    

    return 0;
}

ListNode* createNode(int value){

    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

    if(newNode == NULL){
        printf("Fallo en la asignacion de memoria");
        return NULL;
    }

    newNode->val = value;
    newNode->next = NULL;
    
    return newNode;
}

void insertAtEnd(ListNode** head,int value){

    ListNode* newNode = createNode(value);

    // Si la lista esta vacia, actualizamos *head para que apunte a newNode
    if(*head == NULL){
        *head = newNode;
        return;
    }

    //  Si no esta vacia, recorremos hasta el final
    ListNode* current = *head;

    while (current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
    //newNode->next = NULL;

}

void printList(ListNode* head){

    // Comprobar si la lista esta vacia, no imprimir nada
    if(head == NULL){
        printf("Lista vacia\n");
        return;
    }

    // Si no esta vacia, recorrer toda la lista e imprimir
    ListNode* current = head;

    while (current != NULL)
    {
        printf("%d -> ", current->val);
        current = current->next;
    } 
    printf("NULL\n");
}