#include "monty.h"

/**
 * f_add - adds the top two elements of the stack
 * @head: pointer to the head of the stack
 * @count: line number where the operation is performed
 */
void f_add(stack_t **head, unsigned int count)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", count);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    int sum = (*head)->n + (*head)->next->n;
    (*head)->next->n = sum;

    stack_t *temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
}
