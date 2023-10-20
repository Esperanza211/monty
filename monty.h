#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <ctype.h>
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
		int n;
		struct stack_s *prev;
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
typedef struct Data
{
		char *buff;
		size_t size;
		FILE *stream;
		int line_number;
		stack_t *stack;
		instruction_t instruct[18];
		char *format; /* LIFO & FIFO */
} Data;
extern Data vars;

/* execute_line.c */
int execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);
int set_format(const char *format);

/* 0-opcodes.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* 1-opcodes.c */
void arithmetic_op(stack_t **stack, unsigned int line_number, void (*operation)(stack_t **), const char *op_symbol);
void add(stack_t **stack, unsigned int line_number);
void add_operation(stack_t **stack);
void sub(stack_t **stack, unsigned int line_number);
void sub_operation(stack_t **stack);

/* 2-opcodes.c*/
int execute_stack_operation(stack_t **stack, unsigned int line_number, const char *opcode);
int execute_mod(stack_t **stack, unsigned int line_number);

/*tools.c*/
int init_instructions(void);
void free_all(void);
int is_integer(const char *str);
int push_value(int value);
int add(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
