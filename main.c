#include "monty.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    bus_t bus = {file, NULL, NULL, 0}; // Initialize the bus

    stack_t *head = NULL; // Initialize the stack head
    unsigned int count = 0;

    char *line = NULL;
    size_t size = 0;
    ssize_t read_line;

    while ((read_line = getline(&line, &size, file)) != -1) {
        bus.content = line;
        count++;

        if (read_line > 0) {
            execute(line, &head, count, file); // Execute the instruction
        }
    }

    free(line);
    free_stack(head); // Clean up the stack
    fclose(file); // Close the file

    return EXIT_SUCCESS;
}
