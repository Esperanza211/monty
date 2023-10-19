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

void execute_opcode(char *opcode)
{
    if (strcmp(opcode, "push") == 0)
    {
        push(&vars.stack, 5);
    }
    else if (strcmp(opcode, "pop") == 0)
    {
        pop(&vars.stack);
    }
    else if (strcmp(opcode, "print") == 0)
    {
        print_stack(&vars.stack);
    }
}

int main()
{
    char *opcode[] = {"push", "push", "push", "pop", "pop", "print"};

    for (int i = 0; i < 6; i++)
    {
        execute_opcode(opcode[i]);
    }

    return 0;
}
