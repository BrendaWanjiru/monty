#include "monty.h"

/**
  *process_line - Process single line of bytecode
  *@line: line to be processed
  *@stack: Pointer to stack
  *@line_number: line number
  */
void process_line(char *line, unsigned int *line_number, stack_t **stack)
{
	char *opcode;

	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';
	if (strlen(line) == 0 || line[0] == '#')
		return;
	opcode = strtok(line, " \t\n");

	if (opcode != NULL)
	{
		int i = 0;

		while (instructions[i].opcode != NULL)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(stack, *line_number);
				break;
			}
			i++;
		}
		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", *line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * main - Monty interpreter entry point
 * @argc: number of command-line arguments
 * @argv: array with command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *bytecode_file;
	char *line = NULL;
	size_t line_len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	bytecode_file = fopen(argv[1], "r");
	if (!bytecode_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &line_len, bytecode_file) != -1)
	{
		line_number++;
		process_line(line, &line_number, &stack);
	}
	free(line);
	fclose(bytecode_file);
	return (EXIT_SUCCESS);
}
