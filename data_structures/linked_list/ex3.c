/* Crear una Linked list */

#include<stdio.h>
#include<stdlib.h>


typedef struct ListNode{
    int value;
    struct ListNode* next;
}ListNode;


ListNode* createNode(int val);
void insertAtEnd(ListNode** head, int val);
void printList(ListNode* head);

int main(void){

    ListNode* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    printList(head);

    return 0;
}

ListNode* createNode(int val){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if(newNode == NULL){
        printf("Failed memory allocation");
        return NULL;
    }

    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(ListNode** head, int val){

    ListNode* newNode = createNode(val); // create a new node to add at the end of the list (example: val= 5,   5 -> NULL will be added to the list )
    ListNode* current;

    // Verify either the list is empty or no
    if(*head == NULL){
        *head = newNode;
        return;
    }

    current = *head;
    // if the list is not empty iterate over list
    while (current->next != NULL){
        current = current->next;
    }
    
    current->next = newNode;
}

void printList(ListNode* head){

    if(head == NULL){
        printf("Failed memory allocation");
        return;
    }

    ListNode* current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }

    printf("NUll");
    

}


// 12 -> 13 -> 15 -> NULL