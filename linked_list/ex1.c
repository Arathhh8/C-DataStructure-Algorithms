// This is my first time coding with linked list

#include<stdio.h>
#include<stdlib.h>

// Structure to create a LinkedList

typedef struct node{
    int value;
    struct node* next;
}node;


node* createLinkedList(int n);
void printLinkedList(node* head);

int main(void){

    int n = 0;
    node* HEAD = NULL;
    printf("\nHow many nodes: ");
    scanf("%d", &n);
    HEAD = createLinkedList(n);
    printLinkedList(HEAD);

    return 0;
}


node* createLinkedList(int n){

    int i = 0;
    node* head = NULL;
    node* temp = NULL;
    node* p = NULL;

    for(i = 0; i < n; i++){
        // let us create individual isolated node
        temp = (node*)malloc(sizeof(node));
        printf("\nEnter the data for node number %d: ", i + 1);
        scanf("%d", &(temp->value));

        temp->next = NULL;

        if(head == NULL){
            head = temp; // if head is equal to NULL, then, head is empty, so, now head is equal to temp
        }else{
            p = head;
            while(p->next != NULL)
                p = p->next;

            p->next = temp;
        }
    }

    return head;
}

void printLinkedList(node* head){

    node* p = head;

    while(p != NULL){
        printf("\t%d->",p->value);
        p = p->next;
    }
}