#include "monty.h"

/**
 * execute_stack_operation - Executes various stack operations based on the opcode.
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exists
 * @opcode: the opcode to execute
 *
 * Return: 0 if success, otherwise return EXIT_FAILURE
 */
int execute_stack_operation(stack_t **stack, unsigned int line_number, const char *opcode)
{
	if (strcmp(opcode, "mod") == 0) {
		return execute_mod(stack, line_number);
	} else if (strcmp(opcode, "pchar") == 0) {
		return execute_pchar(stack, line_number);
	} else if (strcmp(opcode, "pstr") == 0) {
		return execute_pstr(stack, line_number);
	} else if (strcmp(opcode, "rotl") == 0) {
		return execute_rotl(stack, line_number);
	} else if (strcmp(opcode, "rotr") == 0) {
		return execute_rotr(stack, line_number);
	}

	return EXIT_FAILURE;
}

/**
 * execute_mod - Computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exists
 *
 * Return: 0 if success, otherwise return EXIT_FAILURE
 */
int execute_mod(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next || (*stack)->n == 0) {
		if (*stack && (*stack)->next) {
			fprintf(stderr, "L%u: division by zero\n", line_number);
		} else {
			fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		}
		free_all();
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	} else {
		(*stack)->next->n = (*stack)->next->n % (*stack)->n;
		pop(stack, line_number);
	}
	return EXIT_SUCCESS;
}


