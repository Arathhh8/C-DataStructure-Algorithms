/**
 * linked_list_funcitons.c
 * @brief Header file to the linked list functions 
 * 
 * Autor: Arathhh8
*/
#ifndef INC_LINKED_LIST_FUNCTIONS_H_
#define INC_LINKED_LIST_FUNCTIONS_H_

#include<stdio.h>
#include<stdlib.h>

/**
 * @brief Main structure of nodes.
 * 
 * This structure represents a node in a linked list. It contains an integer value
 * and a pointer to the next node in the list.
 */
typedef struct ListNode
{
    int val;                  /**< The value stored in the node */
    struct ListNode* next;    /**< Pointer to the next node in the list */
} ListNode;

/**
 * @brief Creates a new node that points to the next node in the list.
 * 
 * This function allocates memory for a new node, sets its value to the
 * provided integer, and initializes its next pointer to NULL.
 * 
 * @param val The value to be stored in the new node.
 * @return A pointer to the newly created node.
 */
ListNode* createNode(int val);

/**
 * @brief Creates a new node at the end of the list.
 * 
 * This function allocates a new node with the given value and 
 * appends it to the end of the linked list. If the list is empty,
 * the new node becomes the head of the list.
 * 
 * @param head A pointer to the pointer to the head of the list.
 * @param val The value to be added to the new node.
 */

void createNodeAtEnd(ListNode** head, int val);

/**
 * @brief Prints the linked list.
 * 
 * This function traverses the linked list starting from the head node
 * and prints the value of each node. If the list is empty, it prints
 * a message indicating that the list is empty.
 * 
 * @param head A pointer to the head of the list.
 */
void printList(ListNode* head);

/**
 * @brief Deletes first node in the list.
 * 
 * This function traverses the linked list starting from the head node
 * and prints the value of each node. If the list is empty, it prints
 * a message indicating that the list is empty.
 * 
 * @param head A pointer to the head of the list.
 */
void deleteFirstNode(ListNode** head);

/**
 * @brief Finds a node by value.
 * 
 * This function 
 * 
 * @param head A pointer to the head of the list.
 * @param val
 */
void findNodeByValue(ListNode** head, int val);

#endif /* INC_LINKED_LIST_FUNCTIONS_H_ */