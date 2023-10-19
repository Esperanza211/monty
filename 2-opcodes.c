#include "monty.h"

/**
 * stack_mod - Compute the remainder of the division of the second top element of
 * the stack by the top element of the stack.
 */
void stack_mod(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next || (*stack)->data == 0)
	{
		if (*stack && (*stack)->next)
			fprintf(stderr, "L%u: Division by zero\n", line_number);
		else
			fprintf(stderr, "L%u: Can't mod, stack too short\n", line_number);
		free_all();
		fclose(vars->stream);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->data = (*stack)->next->data % (*stack)->data;
		pop(stack, line_number);
	}
}

/**
 * stack_print_char - Print the character at the top of the stack, followed by a new line.
 */
void stack_print_char(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: Can't pchar, stack is empty\n", line_number);
		free_all();
		fclose(vars->stream);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->data < 0 || (*stack)->data > 127)
	{
		fprintf(stderr, "L%u: Can't pchar, value is out of range\n", line_number);
		free_all();
		fclose(vars->stream);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->data);
}

/**
 * stack_print_string - Print the string starting at the top of the stack, followed by a new line.
 */
void stack_print_string(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	while (tmp)
	{
		if (tmp->data <= 0 || tmp->data > 127)
			break;
		printf("%c", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * stack_rotate_left - Rotate the stack to the top.
 */
void stack_rotate_left(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	if (*stack && (*stack)->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (*stack);
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		tmp->next->next = NULL;
		tmp->next->prev = tmp;
	}
}

/**
 * stack_rotate_right - Rotate the stack to the bottom.
 */
void stack_rotate_right(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	if (*stack && (*stack)->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *stack;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		(*stack)->prev = tmp;
		(*stack) = tmp;
	}
}

