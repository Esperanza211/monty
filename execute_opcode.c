#include "monty.h"

/**
 * execute_opcode - Calls the function associated with the opcode.
 * @opcode: The opcode to execute.
 * @stack: A pointer to the stack.
 * @line_number: The line number where the opcode exists.
 *
 * Return: 0 if successful, otherwise return EXIT_FAILURE.
 */
int execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
    for (int i = 0; vars.instruct[i].opcode; i++)
    {
        if (strcmp(vars.instruct[i].opcode, opcode) == 0)
        {
            vars.instruct[i].f(stack, line_number);
            return EXIT_SUCCESS;
        }
    }

    return EXIT_FAILURE;
}

/**
 * set_format - Sets the format of the data (LIFO or FIFO).
 * @format: The desired format ("LIFO" or "FIFO").
 *
 * Return: 1 if the format is valid, 0 otherwise.
 */
int set_format(const char *format)
{
    if (strcmp(format, "LIFO") == 0 || strcmp(format, "FIFO") == 0)
    {
        vars.format = format;
        return 1;
    }
    return 0;
}

