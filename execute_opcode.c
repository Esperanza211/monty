#include "monty.h"
/**
 * execute_opcode - call function of the opcode
 * @opcode: the opcode
 *
 * Return: 0 if success otherwise return EXIT_FAILURE
 */
int execute_opcode(char *opcode)
{
	int i;

	if (opcode[0] == '#')
		return (EXIT_SUCCESS);
	for (i = 0; vars.instruct[i].opcode; i++)
	{
		if (strcmp(vars.instruct[i].opcode, opcode) == 0)
		{
			vars.instruct[i].f(&vars.stack, vars.line_number);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}
/**
 * stack - sets the format of the data to a stack (LIFO).
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	vars.format = "LIFO";
}
/**
 * queue - sets the format of the data to a queue (FIFO).
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	vars.format = "FIFO";
}
