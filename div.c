#include "monty.h"

/**
 * f_div - divides second top by top element of stack.
 * @head: parameter for head
 * @count: line_number parameter
 */
void f_div(stack_t **head, unsigned int count)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", count);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    int divisor = (*head)->n;
    if (divisor == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", count);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    stack_t *second_top = (*head)->next;
    second_top->n /= divisor;

    stack_t *temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
}
