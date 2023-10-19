#include "monty.h"

/**
 * multiply_nodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void multiply_nodes(stack_t **stack, unsigned int line_number)
{
    int sum;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL) {
        more_err(8, line_number, "mul");
    }

    (*stack) = (*stack)->next;
    sum = (*stack)->n * (*stack)->prev->n;
    (*stack)->n = sum;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * modulo_nodes - Divides the top two elements of the stack, and returns the remainder.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void modulo_nodes(stack_t **stack, unsigned int line_number)
{
    int sum;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL) {
        more_err(8, line_number, "mod");
    }

    if ((*stack)->n == 0) {
        more_err(9, line_number);
    }

    (*stack) = (*stack)->next;
    sum = (*stack)->n % (*stack)->prev->n;
    (*stack)->n = sum;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
