#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: The head of the stack.
 * @line_number: The line number where the opcode exists.
 *
 * Return: (void)
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *number = strtok(NULL, " \t\n");
    if (number == NULL || _isdigit(number) == EXIT_FAILURE)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_all();
        fclose(vars.stream);
        exit(EXIT_FAILURE);
    }

    int value = atoi(number);
    add_node(stack, value);
}

/**
 * pall - Prints all the values on the stack.
 * @stack: The head of the stack.
 * @line_number: The line number where the opcode exists.
 *
 * Return: (void)
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: The head of the stack.
 * @line_number: The line number where the opcode exists.
 *
 * Return: (void)
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        free_all();
        fclose(vars.stream);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack.
 * @stack: The head of the stack.
 * @line_number: The line number where the opcode exists.
 *
 * Return: (void)
 */
void pop(stack_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        free_all();
        fclose(vars.stream);
        exit(EXIT_FAILURE);
    }

    stack_t *top = *stack;
    *stack = (*stack)->next;

    if (*stack)
        (*stack)->prev = NULL;

    free(top);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: The head of the stack.
 * @line_number: The line number where the opcode exists.
 *
 * Return: (void)
 */
void swap(stack_t **stack, unsigned int line_number)
{
    if (!(*stack) || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        free_all();
        fclose(vars.stream);
        exit(EXIT_FAILURE);
    }

    int tmp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = tmp;
}
