/* Una "queue" (o cola) en C es una estructura de datos que sigue el principio FIFO (First In, First Out), donde el primer elemento en ser añadido es el primero en ser eliminado. En una cola, los elementos se agregan en un extremo (conocido como el "final" o "rear") y se eliminan en el otro extremo (conocido como el "frente" o "front").*/

#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{

    int val;
    struct ListNode* next;
    
}ListNode;


void push(ListNode** front, int val){
    if(*front == NULL){
        *front = (ListNode*)malloc(sizeof(ListNode));
        (*front)->val = val;
        (*front)->next = NULL;
    }else{
        ListNode* tmp = *front;
        ListNode* last = NULL;
        while( tmp != NULL){
            last = tmp;
            tmp = tmp->next;
        }


        ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
        new_node->val = val;
        new_node->next = NULL;
        last->next = new_node;
    }
}

int pop(ListNode** front){

    int val_tmp = (*front)->val;
    ListNode* tmp = *front;
    *front = (*front)->next;
    free(tmp);

    return val_tmp;
}

void printQueue(ListNode** front){

    ListNode* tmp = *front;

    while( tmp != NULL){
        printf("%d -> ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");

}

int main(void){

    ListNode* front = NULL;
    
    push(&front, 0);
    push(&front, 1);
    push(&front, 2);
    push(&front, 3);


    printQueue(&front);

    printf("Despues de llamar pop() tenemos: %d\n", pop(&front));
    printQueue(&front);

    return 0;
}