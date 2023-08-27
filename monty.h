#ifndef MONTY_H
#define MONTY_H

// Include necessary headers
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Define the stack node structure
typedef struct StackNode {
    int data;
    struct StackNode *prev;
    struct StackNode *next;
} StackNode;

// Define the interpreter data structure
typedef struct InterpreterData {
    char *arg;
    FILE *file;
    char *content;
    int lifi;
} InterpreterData;

// Define the instruction function type
typedef void (*InstructionFunction)(StackNode **stack, unsigned int line_number);

// Define the instruction structure
typedef struct Instruction {
    char *opcode;
    InstructionFunction func;
} Instruction;

// External declaration for interpreter data
extern InterpreterData interpreterData;

// Function prototypes
char *_reallocate(char *ptr, unsigned int old_size, unsigned int new_size);
size_t readStdin(char **lineptr, int file);
char *cleanLine(char *content);

void push(StackNode **head, unsigned int count);
void pall(StackNode **head, unsigned int count);
void pint(StackNode **head, unsigned int count);
int executeInstruction(char *content, StackNode **head, unsigned int count, FILE *file);
void freeStack(StackNode *head);

void pop(StackNode **head, unsigned int count);
void swap(StackNode **head, unsigned int count);
void add(StackNode **head, unsigned int count);
void nop(StackNode **head, unsigned int count);
void sub(StackNode **head, unsigned int count);
void div(StackNode **head, unsigned int count);
void mul(StackNode **head, unsigned int count);
void mod(StackNode **head, unsigned int count);
void pchar(StackNode **head, unsigned int count);
void pstr(StackNode **head, unsigned int count);
void rotl(StackNode **head, unsigned int count);
void rotr(StackNode **head, unsigned int count);
void enqueue(StackNode **head, int data);
void stack(StackNode **head, unsigned int count);

#endif
