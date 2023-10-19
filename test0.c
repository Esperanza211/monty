#include "monty.h"

typedef struct stack_node_s {
    int data;
    struct stack_node_s *next;
} stack_node_t;

stack_node_t *stack_push(stack_node_t **top, int value) {
    stack_node_t *new_node = (stack_node_t *) malloc(sizeof(stack_node_t));
    if (!new_node) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = *top;
    *top = new_node;
    return new_node;
}

int stack_pop(stack_node_t **top) {
    if (!*top) {
        fprintf(stderr, "Error: empty stack\n");
        exit(EXIT_FAILURE);
    }
    stack_node_t *temp = *top;
    int popped_value = temp->data;
    *top = temp->next;
    free(temp);
    return popped_value;
}

void stack_pall(stack_node_t *top) {
    stack_node_t *temp = top;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    stack_node_t *stack_top = NULL;
    char input[100];
    while (fgets(input, sizeof(input), stdin)) {
        char *token = strtok(input, " \t\n");
        if (!token) continue;
        if (strcmp(token, "push") == 0) {
            token = strtok(NULL, " \t\n");
            if (!token) {
                fprintf(stderr, "Error: usage: push integer\n");
                continue;
            }
            int value = atoi(token);
            if (value == 0 && token[0] != '0') {
                fprintf(stderr, "Error: usage: push integer\n");
                continue;
            }
            stack_push(&stack_top, value);
        } else if (strcmp(token, "pall") == 0) {
            stack_pall(stack_top);
        } else {
            fprintf(stderr, "Error: unknown command\n");
        }
    }
    return 0;
}
