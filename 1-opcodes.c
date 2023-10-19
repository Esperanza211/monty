#include "monty.h"

/**
 * stack_add - Add the top two elements of the stack.
 */
void stack_add(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: Can't add, stack too short\n", line_number);
		free_all();
		fclose(vars->stream);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n += (*stack)->n;
		pop(stack, line_number);
	}
}

/**
 * stack_nop - Do nothing.
 */
void stack_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * stack_sub - Subtract the top element from the second top element.
 */
void stack_sub(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: Can't subtract, stack too short\n", line_number);
		free_all();
		fclose(vars->stream);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n -= (*stack)->n;
		pop(stack, line_number);
	}
}

/**
 * stack_divide - Divide the second top element by the top element.
 */
void stack_divide(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next || (*stack)->n == 0)
	{
		if (*stack && (*stack)->next)
			fprintf(stderr, "L%u: Division by zero\n", line_number);
		else
			fprintf(stderr, "L%u: Can't divide, stack too short\n", line_number);
		free_all();
		fclose(vars->stream);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n /= (*stack)->n;
		pop(stack, line_number);
	}
}

/**
 * stack_multiply - Multiply the second top element by the top element.
 */
void stack_multiply(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: Can't multiply, stack too short\n", line_number);
		free_all();
		fclose(vars->stream);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n *= (*stack)->n;
		pop(stack, line_number);
	}
}

