#include "monty.h"

/**
 * print_character - Prints the ASCII value at the top of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
int print_character(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;
    int ascii;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        printf("Error: invalid operation at line %u.\n", line_number);
        return (-1);
    }
    tmp = (*stack)->next;
    ascii = tmp->n;
    if (ascii <= 0 || ascii > 127)
    {
        printf("Error: invalid value at line %u.\n", line_number);
        return (-1);
    }
    printf("%c\n", ascii);
    return (0);
}

/**
 * print_string - Prints all ASCII values in the stack, until it encounters a non-ASCII value or the end of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_string(stack_t **stack, unsigned int line_number)
{
    int ascii;
    stack_t *tmp;

    if (stack == NULL || *stack == NULL) {
        printf("\n");
        return;
    }

    tmp = *stack;
    while (tmp != NULL) {
        ascii = tmp->n;
        if (ascii <= 0 || ascii > 127) {
            break;
        }

        printf("%c", ascii);
        tmp = tmp->next;
    }

    printf("\n");
}

/**
 * rotate_left - Rotates the stack to the left, moving the top node to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void rotate_left(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL) {
        return;
    }

    tmp = *stack;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = *stack;
    (*stack)->prev = tmp;
    *stack = (*stack)->next;
    (*stack)->prev->next = NULL;
    (*stack)->prev = NULL;
}

/**
 * rotate_right - Rotates the stack to the right, moving the bottom node to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void rotate_right(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL) {
        return;
    }

    tmp = *stack;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = *stack;
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    (*stack)->prev = tmp;
    (*stack) = tmp;
}
