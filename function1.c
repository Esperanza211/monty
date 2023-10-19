#include "monty.h"

/**
 * push_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 *
 * Return: void
 */
void push_to_stack(stack_t **new_node)
{
    stack_t *tmp;

    if (new_node == NULL || *new_node == NULL) {
        exit(EXIT_FAILURE);
    }

    if (head == NULL) {
        head = *new_node;
        return;
    }

    tmp = head;
    head = *new_node;
    head->next = tmp;
    tmp->prev = head;
}

/**
 * print_stack - Prints all nodes in the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * Return: void
 */
void print_stack(stack_t **stack)
{
    stack_t *tmp;

    if (stack == NULL) {
        exit(EXIT_FAILURE);
    }

    tmp = *stack;
    while (tmp != NULL) {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}

/**
 * pop_from_stack - Removes the top node from the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * Return: void
 */
void pop_from_stack(stack_t **stack)
{
    stack_t *tmp;

    if (stack == NULL || *stack == NULL) {
        more_err(7, 0);
    }

    tmp = *stack;
    *stack = tmp->next;
    if (*stack != NULL) {
        (*stack)->prev = NULL;
    }

    free(tmp);
}

/**
 * print_top_of_stack - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * Return: void
 */
void print_top_of_stack(stack_t **stack)
{
    if (stack == NULL || *stack == NULL) {
        more_err(6, 0);
    }

    printf("%d\n", (*stack)->n);
}
