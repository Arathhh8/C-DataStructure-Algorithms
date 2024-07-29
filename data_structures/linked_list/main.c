/*
Exercise: Basic Implementation of a Linked List

Definition of the Structure:
Define a Node structure that contains an integer and a pointer to the next node.

Function to Create a New Node:
Implement a function that creates a new node with a given integer value and returns a pointer to this node.

Function to Add a Node to the Beginning of the List:
Implement a function that takes an integer value and a pointer to the first node of the list, and adds a new node to the beginning of the list.

Function to Print the List:
Implement a function that prints all the values of the nodes in the linked list from the first to the last.

Tasks:

Define the Node structure.
Write a function to create a new node.
Write a function to add a node to the beginning of the list.
Write a function to print all the nodes in the list.
Example Usage:

Create an empty linked list.
Add some nodes to the beginning of the list with values 1, 2, and 3.
Print the resulting list.
*/
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

    printList(head);

    deleteFirstNode(&head);

    printList(head);

    return 0;
}