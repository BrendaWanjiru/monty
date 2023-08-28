#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

/* these are the standard libraries*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* these are data structures */

/**
 * struct stack_s - doubly linked list representation of stack (or queue)
 * @n: integer
 * @prev: points to previous element of the stack (or queue)
 * @next: points to next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and function related
 * @opcode: the opcode
 * @f: function to handle opcode related
 *
 * Description: opcode and related function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void push_stack(stack_t **stack, int value);
int is_valid_integer(const char *str);
void handle_unknown_opcode(char *opcode, unsigned int line_number);
void execute_opcode(char *line, unsigned int line_number, stack_t **stack);
void push(stack_t **stack, char *argument, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void process_line(char *line, unsigned int *line_number, stack_t **stack);
void sub(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul_op(stack_t **stack, unsigned int line_number);
void mod_op(stack_t **stack, unsigned int line_number);
void pchar_op(stack_t **stack, unsigned int line_number);
#endif
