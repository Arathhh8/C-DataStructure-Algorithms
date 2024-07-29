/**
 * linked_list_funcitons.c
 * @brief Source file to the linked list functions 
 * 
 * Autor: Arathhh8
*/
#include"linked_list_functions.h"

/**
 * @brief Creates a new node that points to the next node in the list.
 * 
 * This function allocates memory for a new node, sets its value to the
 * provided integer, and initializes its next pointer to NULL.
 * 
 * @param val The value to be stored in the new node.
 * @return A pointer to the newly created node.
 */
ListNode* createNode(int val)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}

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
void createNodeAtEnd(ListNode** head, int val){

    ListNode* newNode = createNode(val);

    // Check if the list is empty. 
    if(*head == NULL){
        *head = newNode;
        return;
    }

    ListNode* current = *head;

    // Go throught the last node in the list.
    while(current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
}

/**
 * @brief Prints the linked list.
 * 
 * This function traverses the linked list starting from the head node
 * and prints the value of each node. If the list is empty, it prints
 * a message indicating that the list is empty.
 * 
 * @param head A pointer to the head of the list.
 */
void printList(ListNode* head)
{
    // Check if the list is empty.
    if(head == NULL)
    {
        printf("List is empty.\n");
    }

    ListNode* current = head;

    // Print list
    while(current != NULL)
    {
        printf("%d -> ", current->val);
        current = current->next;
    }

    printf("NULL\n");
}