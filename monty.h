#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int data;
    struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct Data - struct of datas to be used as global variable
 * @buff: getline buffer
 * @size: getline buffer size
 * @stream: file stream
 * @line_number: line number
 * @stack: head of the stack
 * @instruct: array of instructions
 */
typedef struct InterpreterData
{
    char *buff;
    size_t size;
    FILE *stream;
    int line_number;
    stack_t *stack;
    instruction_t instruct[18];
    char *format; /* LIFO & FIFO */
} InterpreterData;

InterpreterData *vars = NULL;

/* execute_operations */
int execute_opcode(char *opcode);
void set_data_structure(stack_t **stack, unsigned int line_number, const char *format);

/* code0_functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* 1_opcode */
void stack_add(stack_t **stack, unsigned int line_number);
void stack_nop(stack_t **stack, unsigned int line_number);
void stack_sub(stack_t **stack, unsigned int line_number);
void stack_divide(stack_t **stack, unsigned int line_number);
void stack_multiply(stack_t **stack, unsigned int line_number);

/* 2_opcode */
void stack_mod(stack_t **stack, unsigned int line_number);
void stack_print_char(stack_t **stack, unsigned int line_number);
void stack_print_string(stack_t **stack, unsigned int line_number);
void stack_rotate_left(stack_t **stack, unsigned int line_number);
void stack_rotate_right(stack_t **stack, unsigned int line_number);

/* tools.c */
void initialize_vars(void);
void instruct_init(void);
void free_all(void);
int is_digit(const char *str);
void add_node(stack_t **head, const int n);

#endif /* MONTY_H */
