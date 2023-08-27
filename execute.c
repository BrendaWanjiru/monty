#include "monty.h"

/**
 * execute_opcode - Executes the given opcode.
 * @opcode: The opcode to execute.
 * @head: Pointer to the stack.
 * @count: Line number.
 * @file: Pointer to the Monty file.
 * @content: Line content.
 * 
 * Return: 0 if successful, 1 if unknown opcode.
 */
int execute_opcode(char *opcode, stack_t **head, unsigned int count, FILE *file, char *content)
{
    instruction_t opst[] = {
        {"push", f_push},
        {"pall", f_pall},
        {"pint", f_pint},
        {"pop", f_pop},
        {"swap", f_swap},
        {"add", f_add},
        {"nop", f_nop},
        {"sub", f_sub},
        {"div", f_div},
        {"mul", f_mul},
        {"mod", f_mod},
        {"pchar", f_pchar},
        {"pstr", f_pstr},
        {"rotl", f_rotl},
        {"rotr", f_rotr},
        {"queue", f_queue},
        {"stack", f_stack},
        {NULL, NULL}
    };

    int i = 0;

    if (opcode[0] == '#')
        return 0;

    for (i = 0; opst[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, opst[i].opcode) == 0)
        {
            opst[i].f(head, count);
            return 0;
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", count, opcode);
    fclose(file);
    free(content);
    free_stack(*head);
    exit(EXIT_FAILURE);
}

/**
 * execute - Parses and executes Monty bytecode.
 * @content: Line content.
 * @head: Pointer to the stack.
 * @count: Line number.
 * @file: Pointer to the Monty file.
 */
void execute(char *content, stack_t **head, unsigned int count, FILE *file)
{
    char *opcode = strtok(content, " \n\t");
    char *arguments = strtok(NULL, " \n\t");

    if (opcode)
    {
        if (execute_opcode(opcode, head, count, file, content) != 0)
        {
            fclose(file);
            free(content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char **argv)
{
    // Initialize variables, open file, and read lines
    // Loop through lines and call execute function
    // Clean up and close the file
    return 0;
}
