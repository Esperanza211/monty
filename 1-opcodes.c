#include "monty.h"

/**
 * arithmetic_op - performs arithmetic operations on the top two elements of the stack.
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exists
 * @operation: a function pointer to the specific arithmetic operation
 * @op_symbol: a string representing the arithmetic operation symbol
 *
 * Return: (void)
 */
void arithmetic_op(stack_t **stack, unsigned int line_number, void (*operation)(stack_t **), const char *op_symbol)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op_symbol);
		free_all();
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	operation(stack);
}

/**
 * add - adds the top two elements of the stack.
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exists
 *
 * Return: (void)
 */
void add(stack_t **stack, unsigned int line_number)
{
	arithmetic_op(stack, line_number, add_operation, "add");
}

/**
 * add_operation - actual addition operation.
 * @stack: the head of the stack
 *
 * Return: (void)
 */
void add_operation(stack_t **stack)
{
	(*stack)->next->n += (*stack)->n;
	pop(stack, 0); 
}

/**
 * sub - subtracts the top element of the stack from the second top element.
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exists
 *
 * Return: (void)
 */
void sub(stack_t **stack, unsigned int line_number)
{
	arithmetic_op(stack, line_number, sub_operation, "sub");
}

/**
 * sub_operation - actual subtraction operation.
 * @stack: the head of the stack
 *
 * Return: (void)
 */
void sub_operation(stack_t **stack)
{
	(*stack)->next->n -= (*stack)->n;
	pop(stack, 0); 
}
