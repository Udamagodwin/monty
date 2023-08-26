#include "monty.h"

/**
 * pchar_ops -  print the character at the top of the stack,
 * @stack: double pointer to the stack
 * @call_line: the line in which this command is called
 * Return: nothing
 */
void pchar_ops(stack_t **stack, unsigned int call_line)
{
	if (!(*stack)->next)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", call_line);
		global.err_status = EXIT_FAILURE;
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", call_line);
		global.err_status = EXIT_FAILURE;
		return;
	}

	printf("%c\n", (*stack)->next->n);
}


/**
 * pstr_ops - Print the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @call_line: The current working line number of a Monty bytecodes file.
 */
void pstr_ops(stack_t **stack, unsigned int call_line)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)call_line;
}



/**
 * rotb_ops - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @call_line: The current working line number of a Monty bytecodes file.
 */
void rotb_ops(stack_t **stack, unsigned int call_line)
{

	stack_t *topNode, *bottomNode;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	topNode = (*stack)->next;
	bottomNode = (*stack)->next;
	while (bottomNode->next != NULL)
		bottomNode = bottomNode->next;

	bottomNode->prev->next = NULL;
	(*stack)->next = bottomNode;
	bottomNode->prev = *stack;
	bottomNode->next = topNode;
	topNode->prev = bottomNode;

	(void)call_line;
}


/**
 * rott_ops - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @call_line: The current working line number of a Monty bytecodes file.
 */
void rott_ops(stack_t **stack, unsigned int call_line)
{
	stack_t *topNode, *bottomNode;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	topNode = (*stack)->next;
	bottomNode = (*stack)->next;
	while (bottomNode->next != NULL)
		bottomNode = bottomNode->next;

	topNode->next->prev = *stack;
	(*stack)->next = topNode->next;
	bottomNode->next = topNode;
	topNode->next = NULL;
	topNode->prev = bottomNode;

	(void)call_line;
}

