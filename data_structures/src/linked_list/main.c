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

    int valueToFind = 10;
    ListNode* foundNode = findNodeByValue(head, valueToFind);
    if (foundNode) {
        printf("Found node with value %d at address %p\n", valueToFind, (void*)foundNode);
    } else {
        printf("Node with value %d not found in the list.\n", valueToFind);
    }

    printList(head);

    return 0;
}