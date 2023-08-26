#include "monty.h"

/**
 * push_ops - pushes an element to the stack
 * @stack: a double pointer to the stack
 * @call_line: the line which the command will be called
 */
void push_ops(stack_t **stack, unsigned int call_line)
{
    stack_t *newNode = *stack;
    stack_t *temp;
    int num;

    if (!(global.toks_num) || is_dig(global.toks_num) == 0)
    {
        fprintf(stderr, "L%u: usage: push integer\n", call_line);
        global.err_status = EXIT_FAILURE;
        return;
    }
    num = atoi(global.toks_num);
    newNode = add_new_node(num);

    if (check_mode(*stack) == STACK)
    {
        temp = (*stack)->next;
        newNode->prev = *stack;
        newNode->next = temp;
        if (temp)
            temp->prev = newNode;
        (*stack)->next = newNode;
    }
    else
    {
        temp = *stack;
        while (temp->next)
            temp = temp->next;
        newNode->prev = temp;
        newNode->next = NULL;
        temp->next = newNode;
    }
}

/**
 * pall_ops - prints all the values on the stack.
 * @stack: a pointer to the stack
 * @call_line: the line at which this command is called
 */
void pall_ops(stack_t **stack, unsigned int call_line)
{
    stack_t *temp = (*stack)->next;
    (void)call_line;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

/**
 * pint_ops -  prints the value at the top of the stack,
 * followed by a new line
 * @stack: a double pointer to the stack
 * @call_line: Line at which the command will be called
 */
void pint_ops(stack_t **stack, unsigned int call_line)
{
    if (!(*stack)->next)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", call_line);
        global.err_status = EXIT_FAILURE;
        return;
    }
    printf("%d\n", (*stack)->next->n);
}

/**
 * pop_ops -removes the top element of the stack
 * @stack: pointer to the stack
 * @call_line: the line number where the pop command is called
 *
 * Return: nothing
 */
void pop_ops(stack_t **stack, unsigned int call_line)
{
    stack_t *temp;

    if (!(*stack)->next)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", call_line);
        global.err_status = EXIT_FAILURE;
        return;
    }
    temp = (*stack)->next->next;
    free((*stack)->next);
    if (temp)
        temp->prev = *stack;

    (*stack)->next = temp;
}

/**
 * swap_ops - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_no: the line number where the pop command is called
 * Return: nothing
 */
void swap_ops(stack_t **stack, unsigned int line_no)
{
    stack_t *temp = (*stack)->next;
    int stack_len;

    stack_len = size_of_stack((*stack)->next);
    if (stack_len < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
        global.err_status = EXIT_FAILURE;
        return;
    }
    temp = temp->next;
    (*stack)->next->next = temp->next;
    (*stack)->next->prev = temp;
    if (temp->next)
        temp->next->prev = (*stack)->next;
    temp->next = (*stack)->next;
    temp->prev = *stack;
    (*stack)->next = temp;
}
