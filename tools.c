#include "monty.h"

typedef struct stack_t
{
	int n;
	struct stack_t *next;
	struct stack_t *prev;
} stack_t;

void free_all(void);

void add_node(stack_t **head, const int n);
void add_node_end(stack_t **head, const int n);

void print_error(char *s)
{
	fprintf(stderr, "Error: %s\n", s);
	free_all();
	exit(EXIT_FAILURE);
}

int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
			continue;
		if (str[i] < 48 || str[i] > 57)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
	char buffer[1024];
	char *buff, *tok;
	FILE *stream;
	stack_t *stack, *queue;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (!stream)
	{
		fprintf(stderr, "Error: unable to open file '%s'\n", argv[1]);
		return (EXIT_FAILURE);
	}

	stack = NULL;
	queue = NULL;

	while (fgets(buffer, sizeof(buffer), stream))
	{
		buff = buffer;
		tok = strtok(buff, " ");

		if (tok[0] == 'C' || tok[0] == 'L')
		{
			if (_isdigit(tok + 1) == EXIT_FAILURE)
				print_error("invalid argument for 'C' or 'L' command");

			if (tok[0] == 'C')
				add_node(&stack, atoi(tok + 1));
			else
				add_node_end(&queue, atoi(tok + 1));
		}
		else
			print_error("unknown command");
	}

	fclose(stream);
	free_all();
	return (EXIT_SUCCESS);
}

void free_all(void)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	stack = NULL;

	while (queue)
	{
		tmp = queue;
		queue = queue->next;
		free(tmp);
	}
	queue = NULL;
}

void add_node(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	new->next = *head;
	if (*head)
	{
		(*head)->prev = new;
	}
	*head = new;
}

void add_node_end(stack_t **head, const int n)
{
	stack_t *current;

	current = *head;
	while (current->next)
	{
		current = current->next;
	}
	add_node(head, n);
}
