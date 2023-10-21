#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @arg_c: arguments count
 * @arg_v: list of arguments
 * Return: always 0
 */

int main(int arg_c, char *arg_v[])
{
	if (arg_c != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_f(arg_v[1]);
	fr_nodes();
	return (0);
}

/**
 * nds - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *nds(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * fr_nodes - Frees nodes in the stack.
 */
void fr_nodes(void)
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
 * addqueue - Adds a node to the queue.
 * @newnd: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void addqueue(stack_t **newnd, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (newnd == NULL || *newnd == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newnd;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *newnd;
	(*newnd)->prev = tmp;

}
