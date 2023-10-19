#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: The head of the stack.
 * @line_number: The line number where the opcode exists.
 */
void push(stack_t **stack, unsigned int line_number) {
  char *number;

  number = strtok(NULL, " \t\n");
  if (number == NULL || !isdigit(number)) {
    fprintf(stderr, "L%u: usage: push integer\n", line_number);
    free_all();
    fclose(vars->stream);
    exit(EXIT_FAILURE);
  }

  if (strcmp(vars->format, "FIFO") == 0) /* Queue */ {
    add_node(stack, atoi(number));
  } else /* Stack */ {
    add_node(stack, atoi(number));
  }
}

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: The head of the stack.
 * @line_number: The line number where the opcode exists.
 */
void pall(stack_t **stack) {
  stack_t *ptr = *stack;

  while (ptr) {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }
}

/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: The head of the stack.
 * @line_number: The line number where the opcode exists.
 */
void pint(stack_t **stack, unsigned int line_number) {
  if (!*stack) {
    fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
    free_all();
    fclose(vars->stream);
    exit(EXIT_FAILURE);
  }

  printf("%d\n", (*stack)->data);
}

/**
 * pop - Removes the top element of the stack.
 * @stack: The head of the stack.
 * @line_number: The line number where the opcode exists.
 */
void pop(stack_t **stack, unsigned int line_number) {
  if (!*stack) {
    fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
    free_all();
    fclose(vars->stream);
    exit(EXIT_FAILURE);
  }

  if (!(*stack)->next) {
    free(*stack);
    *stack = NULL;
  } else {
    *stack = (*stack)->next;
    free((*stack)->prev);
    (*stack)->prev = NULL;
  }
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: The head of the stack.
 * @line_number: The line number where the opcode exists.
 */
void swap(stack_t **stack, unsigned int line_number) {
  int tmp;

  if (!(*stack) || !(*stack)->next) {
    fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
    free_all();
    fclose(vars->stream);
    exit(EXIT_FAILURE);
  } else {
    tmp = (*stack)->data;
    (*stack)->data = (*stack)->next->data;
    (*stack)->next->data = tmp;
  }
}
