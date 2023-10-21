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
	void (*f)(stack_t **stack, unsigned int linenbr);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);


void error(int _errs, ...);
void more_errs(int error_code, ...);
void str_errs(int _errs, ...);

void open_f(char *f_name);
void read_f(FILE *fd);
int parsef(char *buffer, int linenbr, int i);
void callf(op_func func, char *ops, char *val, int ln, int f);
void find_func(char *ops, char *val, int ln, int i);

stack_t *nds(int n);
void fr_nodes(void);
void addqueue(stack_t **, unsigned int);

void add_stk(stack_t **, unsigned int);
void printf_stk(stack_t **, unsigned int);
void _pop(stack_t **, unsigned int);
void prt_top(stack_t **, unsigned int);

void nopy(stack_t **, unsigned int);
void swapnds(stack_t **, unsigned int);
void addnds(stack_t **, unsigned int);
void subnds(stack_t **, unsigned int);
void divnds(stack_t **, unsigned int);

void mulnds(stack_t **, unsigned int);
void modnds(stack_t **, unsigned int);

void prt_char(stack_t **, unsigned int);
void prt_str(stack_t **, unsigned int);
void rfnsb(stack_t **, unsigned int);
void rlnst(stack_t **, unsigned int);


#endif
