#include "monty.h"

/**
 * init_instructions - Initialize the instruction set.
 *
 * Return: 0 if success, otherwise return EXIT_FAILURE
 */
int init_instructions(void)
{
    const instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {"sub", sub},
        {"div", divid},
        {"mul", mul},
        {"mod", mod},
        {"pchar", pchar},
        {"pstr", pstr},
        {"rotl", rotl},
        {"rotr", rotr},
        {"stack", stack},
        {"queue", queue},
        {NULL, NULL}
    };

    for (int i = 0; instructions[i].opcode; i++) {
        vars.instruct[i] = instructions[i];
    }

    return 0;
}

/**
 * free_all - Free allocated memory.
 *
 * Return: void
 */
void free_all(void)
{
    if (vars.buff)
        free(vars.buff);
    if (vars.stack)
    {
        while (vars.stack)
        {
            stack_t *temp = vars.stack;
            vars.stack = vars.stack->next;
            free(temp);
        }
    }
}

/**
 * is_integer - Check if a string is an integer.
 * @str: String to check.
 *
 * Return: 1 if it's an integer, 0 otherwise.
 */
int is_integer(const char *str)
{
    if (!str || *str == '\0')
        return 0;

    if (*str == '-' || *str == '+')
        str++;

    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }

    return 1;
}

/**
 * push_value - Push a value onto the stack.
 * @value: Value to push.
 *
 * Return: 0 if success, otherwise return EXIT_FAILURE.
 */
int push_value(int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_all();
        fclose(vars.stream);
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->next = NULL;

    if (vars.stack)
    {
        new_node->next = vars.stack;
        vars.stack->prev = new_node;
    }

    vars.stack = new_node;
    return 0;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: The head of the stack.
 * @line_number: The line number where the opcode exists.
 *
 * Return: 0 if success, otherwise return EXIT_FAILURE.
 */
int add(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        free_all();
        fclose(vars.stream);
        exit(EXIT_FAILURE);
    }
    else
    {
        (*stack)->next->n = (*stack)->next->n + (*stack)->n;
        return pop(stack, line_number);
    }
}


