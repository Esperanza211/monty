#include "monty.h"

/**
 * execute_opcode - Executes the given opcode.
 * @opcode: The opcode to execute.
 *
 * Return: 0 if success, or EXIT_FAILURE on failure.
 */
int execute_opcode(char *opcode)
{
	int i = 0;
    if (opcode[0] == '#')
        return EXIT_SUCCESS;

	  while (vars->instruct[i].opcode)
    {
        if (strcmp(vars->instruct[i].opcode, opcode) == 0)
        {
            vars->instruct[i].f(&vars->stack, vars->line_number);
            return EXIT_SUCCESS;
        }

        i++;
    }
    return EXIT_FAILURE;
}

/**
 * set_data_structure - Sets the data structure format (stack or queue).
 * @stack: The head of the stack.
 * @line_number: The line number where the opcode exists.
 * @format: The format to set ("LIFO" for stack, "FIFO" for queue).
 *
 * Return: (void)
 */
void set_data_structure(stack_t **stack, unsigned int line_number, const char *format)
{
    (void) stack;
    (void) line_number;

    vars->format = format;
}

