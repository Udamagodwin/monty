#include "monty.h"

/**
 * stack_init - initialize an empty stack
 *
 * Return: pointer to the new stack
 */
stack_t *stack_init(void)
{
    stack_t *new_stack = malloc(sizeof(stack_t));
    if (new_stack == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_stack->n = STACK;
    new_stack->prev = NULL;
    new_stack->next = NULL;

    return new_stack;
}

/**
 * get_op - matches an operation with its corresponding function
 * @ops: the operation to be matched
 *
 * Return: A pointer to the corresponding function
 */
void (*get_op(char *ops))(stack_t **, unsigned int)
{
	instruction_t func[] = {
		{"push", push_ops},
		{"pall", pall_ops},
		{"pint", pint_ops},
		{"pop", pop_ops},
		{"swap", swap_ops},
		{"add", add_ops},
		{"nop", nop_ops},
		{"sub", sub_ops},
		{"div", div_ops},
		{"mul", mul_ops},
		{"mod", mod_ops},
		{"pchar", pchar_ops},
		{"pstr", pstr_ops},
		{"rotl", rott_ops},
		{"rotr", rotb_ops},
		{"stack", stack_ops},
		{"queue", queue_ops},
		{NULL, NULL}
	};
	int i = 0;

	while (func[i].opcode)
		if (strcmp(ops, func[i++].opcode) == 0)
			return (func[--i].f);

	return (NULL);
}


/**
 * execute - function to execute a Monty bytecode script
 * @l_file: file descriptor for an open Monty bytecode script
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE otherwise
 */
int execute(FILE *l_file)
{
    stack_t *stack = stack_init();
    char *f_read = NULL, *tokenize = NULL;
    size_t len = 0;
    unsigned int line_num = 0;
    void (*op_func)(stack_t **, unsigned int);

    while (getline(&f_read, &len, l_file) != -1)
    {
        line_num++;

        if (*f_read == '\n')
            continue;

        tokenize = strtok(f_read, DELIM);

        if (!tokenize || *tokenize == '#')
            continue;

        global.toks_num = strtok(NULL, DELIM);

        op_func = get_op(tokenize);
        if (!op_func)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_num, tokenize);
            global.err_status = EXIT_FAILURE;
            break;
        }

        op_func(&stack, line_num);
        if (global.err_status == EXIT_FAILURE)
            break;
    }

    free_stack(&stack);
    free(f_read);

    return global.err_status;
}

/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (1).
 *         If the stack_t is in queue mode - QUEUE (0).
 *         Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
    if (stack->n == STACK)
        return STACK;
    else if (stack->n == QUEUE)
        return QUEUE;
    else
        return 2;
}
