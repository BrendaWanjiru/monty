#include "monty.h"

/**
 * free_stack - Frees a doubly linked list in place of a stack.
 * @head: Pointer to stack head.
 */
void free_stack(stack_t *head)
{
    stack_t *current = head; // Pointer to traverse the list
    stack_t *next_node;      // Pointer to hold the next node temporarily
    
    while (current != NULL)
    {
        next_node = current->next; // Store the next node before freeing
        free(current);             // Free the current node
        current = next_node;       // Move to the next node
    }
}
