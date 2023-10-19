#include "monty.h"

Data vars;

/**
 * initialize_vars - Initializes the global variables.
 */
void initialize_vars(void) {
  vars.stream = NULL;
  vars.buff = NULL;
  vars.size = 0;
  vars.line_number = 0;
}

/**
 * open_file - Opens the Monty bytecode file.
 * @filename: The name of the file to open.
 *
 * Returns: A pointer to the file stream, or NULL on error.
 */
FILE *open_file(const char *filename) {
  vars.stream = fopen(filename, "r");
  if (!vars.stream) {
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    exit(EXIT_FAILURE);
  }
  return vars.stream;
}

/**
 * get_opcode - Gets the next opcode from the Monty bytecode file.
 *
 * Returns: A pointer to the opcode string, or NULL on EOF.
 */
char *get_opcode(void) {
  char *opcode = strtok(vars.buff, " \t\n");
  if (!opcode) {
    vars.line_number++;
    return NULL;
  }
  return opcode;
}

/**
 * execute_opcode - Executes the given opcode.
 * @opcode: The opcode to execute.
 *
 * Returns: EXIT_SUCCESS on success, or EXIT_FAILURE on failure.
 */
int execute_opcode(char *opcode) {
  // TODO: Implement this function to execute the given opcode.

  return EXIT_SUCCESS;
}

/**
 * free_all - Frees all allocated resources.
 */
void free_all(void) {
  fclose(vars.stream);
  free(vars.buff);
}

/**
 * main - Entry point for the program.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Returns: EXIT_SUCCESS on success, or EXIT_FAILURE on failure.
 */
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
  }

  initialize_vars();
  open_file(argv[1]);

  while (get_opcode()) {
    if (execute_opcode(opcode) == EXIT_FAILURE) {
      fprintf(stderr, "L%u: unknown instruction %s\n", vars.line_number, opcode);
      free_all();
      fclose(vars.stream);
      exit(EXIT_FAILURE);
    }
  }

  fclose(vars.stream);
  free_all();

  return EXIT_SUCCESS;
}
