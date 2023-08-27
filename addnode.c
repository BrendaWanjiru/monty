#include "monty.h"

void addnode(stack_t **head, int n)
{
    // Create a new node
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the new node
    new_node->n = n;
    new_node->prev = NULL;

    // Update the next pointer of the new node to point to the current head
    new_node->next = *head;

    // Update the previous pointer of the current head if it exists
    if (*head)
        (*head)->prev = new_node;

    // Update the head pointer to the new node
    *head = new_node;
}
