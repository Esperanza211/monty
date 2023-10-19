#include "monty.h"

stack_t *head = NULL;

/**
 * open_file - Opens a file and reads it line by line.
 * @file_name: The path to the file to open.
 *
 * Return: void
 */
void open_file(char *file_name)
{
    FILE *fd = fopen(file_name, "r");
    if (fd == NULL) {
        err(2, file_name);
    }

    read_file(fd);
    fclose(fd);
}

/**
 * read_file - Reads a file line by line and parses each line into tokens.
 * @fd: A pointer to the file descriptor.
 *
 * Return: void
 */
void read_file(FILE *fd)
{
    int line_number;
    char *buffer = NULL;
    size_t len = 0;

    for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++) {
        parse_line(buffer, line_number);
    }

    free(buffer);
}

/**
 * parse_line - Parses a line from the file into tokens and calls the appropriate function
 * for the opcode.
 * @buffer: The line to parse.
 * @line_number: The line number of the line being parsed.
 *
 * Return: void
 */
void parse_line(char *buffer, int line_number)
{
    char *opcode, *value;
    const char *delim = "\n ";

    opcode = strtok(buffer, delim);
    if (opcode == NULL) {
        return;
    }

    value = strtok(NULL, delim);

    find_func(opcode, value, line_number);
}

/**
 * find_func - Finds the appropriate function for the opcode and calls it.
 * @opcode: The opcode to find the function for.
 * @value: The value associated with the opcode.
 * @line_number: The line number of the opcode.
 *
 * Return: void
 */
void find_func(char *opcode, char *value, int line_number)
{
    int i;

    for (i = 0; instructions[i].opcode != NULL; i++) {
        if (strcmp(opcode, instructions[i].opcode) == 0) {
            instructions[i].f(head, value, line_number);
            return;
        }
    }

    err(3, line_number, opcode);
}

/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
    stack_t *node;
    int flag;
    int i;

    flag = 1;
    if (strcmp(op, "push") == 0) {
        if (val != NULL && val[0] == '-') {
            val = val + 1;
            flag = -1;
        }
        if (val == NULL) {
            err(5, ln);
        }
        for (i = 0; val[i] != '\0'; i++) {
            if (isdigit(val[i]) == 0) {
                err(5, ln);
            }
        }
        node = create_node(atoi(val) * flag);
        if (format == 0) {
            func(&node, ln);
        }
        if (format == 1) {
            add_to_queue(&node, ln);
        }
    } else {
        func(&head, ln);
    }
}
