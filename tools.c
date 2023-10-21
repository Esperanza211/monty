#include "monty.h"

/**
 * open_f - opens a file
 * @f_name: the file namepath
 * Return: void
 */

void open_f(char *f_name)
{
	FILE *fd = fopen(f_name, "r");

	if (f_name == NULL || fd == NULL)
		error(2, f_name);

	read_f(fd);
	fclose(fd);
}


/**
 * read_f - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_f(FILE *fd)
{
	int linenbr, i = 0;
	char *buffer = NULL;
	size_t n = 0;

	for (linenbr = 1; getline(&buffer, &n, fd) != -1; linenbr++)
	{
		i = parsef(buffer, linenbr, i);
	}
	free(buffer);
}


/**
 * parsef - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @linenbr: line number
 * @i:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parsef(char *buffer, int linenbr, int i)
{
	char *ops, *val;
	const char *delim = "\n ";

	if (buffer == NULL)
		error(4);

	ops = strtok(buffer, delim);
	if (ops == NULL)
		return (i);
	val = strtok(NULL, delim);

	if (strcmp(ops, "stack") == 0)
		return (0);
	if (strcmp(ops, "queue") == 0)
		return (1);

	find_func(ops, val, linenbr, i);
	return (i);
}

/**
 * find_func - find the appropriate function for the opcode
 * @ops: opcode
 * @val: argument of opcode
 * @i:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *ops, char *val, int ln, int i)
{
	int n;
	int flag;

	instruction_t func_list[] = {
		{"push", add_stk},
		{"pall", printf_stk},
		{"pint", prt_top},
		{"pop", _pop},
		{"nop", nopy},
		{"swap", swapnds},
		{"add", addnds},
		{"sub", subnds},
		{"div", divnds},
		{"mul", mulnds},
		{"mod", modnds},
		{"pchar", prt_char},
		{"pstr", prt_str},
		{"rotl", rfnsb},
		{"rotr", rlnst},
		{NULL, NULL}
	};

	if (ops[0] == '#')
		return;

	for (flag = 1, n = 0; func_list[n].opcode != NULL; n++)
	{
		if (strcmp(ops, func_list[n].opcode) == 0)
		{
			callf(func_list[n].f, ops, val, ln, i);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, ln, ops);
}


/**
 * callf - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @ops: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @f: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void callf(op_func func, char *ops, char *val, int ln, int f)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(ops, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			error(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				error(5, ln);
		}
		node = nds(atoi(val) * flag);
		if (f == 0)
			func(&node, ln);
		if (f == 1)
			addqueue(&node, ln);
	}
	else
		func(&head, ln);
}
