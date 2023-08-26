#include "monty.h"
/**
 * is_dig - To check if the strings is a digit
 * @val: number to be checked
 *
 * Return: 1 if is digit, 0 otherwise
 */

int is_dig(char *val)
{
    if (*val == '-')
        val++;

    while (*val)
    {
        if (*val < '0' || *val > '9')
            return 0;
        val++;
    }
    return 1;
}

/**
 * add_new_node - adds a node to a stack
 * @num: number value of the stack
 * Return: Return nothing;
 */
stack_t *add_new_node(int num)
{
   stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

/**
 * size_of_stack - return the size of a stack
 * @stack: pointer to the stack
 * Return: the size
 */
int size_of_stack(stack_t *stack)
{
    int n = 0;
    stack_t *temp = stack;

    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    return n;
}
