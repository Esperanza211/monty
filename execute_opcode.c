#include "monty.h"

typedef struct vars_t
{
    stack_t *stack;
    char *format;
    int line_number;
} vars_t;

void print_stack(stack_t **stack)
{
    stack_t *temp = *stack;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void execute_opcode(stack_t **stack, unsigned int line_number)
	{
	if (strcmp(opcode, "add") == 0)
{
    stack_add(stack, line_number);
}
else if (strcmp(opcode, "sub") == 0)
{
    stack_sub(stack, line_number);
}
else if (strcmp(opcode, "div") == 0)
{
    stack_divide(stack, line_number);
}
else if (strcmp(opcode, "mul") == 0)
{
    stack_multiply(stack, line_number);
}
}

int main()
{
	unsigned int line_number = 0;
    char *opcode[] = {"push", "push", "push", "pop", "pop", "print"};
	int i;
    for ( i = 0; i < 6; i++)
    {
	    execute_opcode(stack, line_number);
    }

