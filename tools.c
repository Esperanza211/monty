#include "monty.h"

/**
 * initialize_vars - Initializes global variables.
 */
void initialize_vars(void)
{
    vars.buff = NULL;
    vars.size = 0;
    vars.line_number = 1;
    vars.stack = NULL;
    vars.format = "LIFO"; /* stack */

    instruct_init();
}

/**
 * instruct_init - Initializes the instruction array.
 */
void instruct_init(void)
{
    const char *opcodes[] = {
        "push", "pall", "pint", "pop", "swap", "add", "nop",
        "sub", "div", "mul", "mod", "pchar", "pstr",
        "rotl", "rotr", "stack", "queue", NULL
    };
    void (*functions[]) = {
        push, pall, pint, pop, swap, add, nop,
        sub, divid, mul, mod, pchar, pstr,
        rotl, rotr, stack, queue, NULL
    };

    for (int i = 0; opcodes[i] != NULL; i++)
    {
        vars.instruct[i].opcode = opcodes[i];
        vars.instruct[i].f = functions[i];
    }
}

/**
 * free_all - Frees allocated memory.
 */
void free_all(void)
{
    if (vars.buff)
        free(vars.buff);

    while (vars.stack)
        pop(&vars.stack, 0);
}

/**
 * is_digit - Checks if a string is a digit.
 * @str: The string to check.
 *
 * Return: 1 if it's a digit, 0 otherwise.
 */
int is_digit(const char *str)
{
    if (!str)
        return 0;

    if (*str == '-')
        str++;  /* Skip the negative sign if present */

    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }

    return 1;
}

/**
 * add_node - Adds an element to the stack.
 * @head: The top of the stack.
 * @n: The element to add.
 */
void add_node(stack_t **head, const int n)
{
    stack_t *new = malloc(sizeof(stack_t));
    if (!new)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_all();
        fclose(vars.stream);
        exit(EXIT_FAILURE);
    }
    new->n = n;
    new->next = *head;
    new->prev = NULL;

    if (*head)
        (*head)->prev = new;
    *head = new;
}

