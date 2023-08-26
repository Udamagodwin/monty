#include "monty.h"

/**
 * stack_ops - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @call_line: The current working line number of a Monty bytecodes file.
 */
void stack_ops(stack_t **stack, unsigned int call_line)
{
	(*stack)->n = STACK;
	(void)call_line;
}

/**
 * queue_ops - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @call_line: The current working line number of a Monty bytecodes file.
 */
void queue_ops(stack_t **stack, unsigned int call_line)
{
	(*stack)->n = QUEUE;
	(void)call_line;
}

/**
 * nop_ops - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @call_line: The current working line number of a Monty bytecodes file.
 */
void nop_ops(stack_t **stack, unsigned int call_line)
{
	(void)stack;
	(void)call_line;
}

