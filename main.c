#include "monty.h"
Data vars;
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
