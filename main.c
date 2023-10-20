#include "monty.h"
Data vars;
stack_t *head = NULL;

/**
 * main - Monty main program
 * @argc: arguments counter
 * @argv: arguments
 *
 * Return: 0 Always (success)
 */
int main(int argc, char **argv)
{
    char *opcode;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    initialize_vars();
    vars.stream = fopen(argv[1], "r");
    if (!(vars.stream))
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (getline(&vars.buff, &vars.size, vars.stream) != EOF)
    {
        opcode = strtok(vars.buff, " \t\n");
        if (!opcode)
        {
            vars.line_number++;
            continue;
        }
        if (execute_opcode(opcode) == EXIT_FAILURE)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n",
                    vars.line_number, opcode);
            free_all();
            fclose(vars.stream);
            exit(EXIT_FAILURE);
        }
        vars.line_number++;
    }
    fclose(vars.stream);
    free_all();
    exit(EXIT_SUCCESS);
}

/**
 * _node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon success, a pointer to the node. Otherwise NULL.
 */
stack_t *_node(int n)
{
    stack_t *node;

    node = malloc(sizeof(stack_t));
    if (node == NULL)
        _error(4);
    node->next = NULL;
    node->prev = NULL;
    node->n = n;
    return (node);
}

/**
 * f_nodes - Frees nodes in the stack.
 */
void f_nodes(void)
{
    stack_t *tmp;

    if (head == NULL)
        return;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

/**
 * add_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_queue(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
    stack_t *tmp;

    if (new_node == NULL || *new_node == NULL)
        exit(EXIT_FAILURE);
    if (head == NULL)
    {
        head = *new_node;
        return;
    }
    tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *new_node;
    (*new_node)->prev = tmp;
}


