#include "monty.h"


/**
 * div_ops - divides the second top element of the
 * @stack: pointer to the stack
 *  call_line: the line in which this command is called
 * Return: nothing
 */
void div_ops(stack_t **stack, unsigned int call_line)
{
	int size = size_of_stack((*stack)->next);

	if (size < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", call_line);
		global.err_status = EXIT_FAILURE;
		return;
	}
	if (!(*stack)->next->n)
	{
		fprintf(stderr, "L%u: division by zero\n", call_line);
		global.err_status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;

	pop_ops(stack, call_line);
}

/**
 * mul_ops - multiplies the second top element of the stack with
 * @stack: pointer to the stack
 * @call_line: the line in which this command is called
 * Return: nothing
 */
void mul_ops(stack_t **stack, unsigned int call_line)
{
	int size = size_of_stack((*stack)->next);

	if (size < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", call_line);
		global.err_status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;

	pop_ops(stack, call_line);
}

/**
 * mod_ops - computes the rest of the division of the
 * second top element of the stack by the top element of the stack.
 * @stack: double pointer to the stack
 * @call_line: the line in which this command is called
 * Return: nothing
 */
void mod_ops(stack_t **stack, unsigned int call_line)
{
	int size = size_of_stack((*stack)->next);

	if (size < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", call_line);
		global.err_status = EXIT_FAILURE;
		return;
	}
	if (!(*stack)->next->n)
	{
		fprintf(stderr, "L%u: division by zero\n", call_line);
		global.err_status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	pop_ops(stack, call_line);
}


/**
 * add_ops - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @call_line: the line number where the pop command is called
 * Return: nothing
 */
void add_ops(stack_t **stack, unsigned int call_line)
{
	int size = size_of_stack((*stack)->next);

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", call_line);
		global.err_status = EXIT_FAILURE;
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;

	pop_ops(stack, call_line);
}

/**
 * sub_ops - subtracts the top element of the stack
 * @stack: double pointer to the stack
 * @call_line: the line number where the pop command is called
 * Return: nothing
 */
void sub_ops(stack_t **stack, unsigned int call_line)
{
int size = size_of_stack((*stack)->next);

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", call_line);
		global.err_status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;

	pop_ops(stack, call_line);

}

