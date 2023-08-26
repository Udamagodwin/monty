#ifndef __MONTY_H__
#define __MONTY_H__
#define  _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK 1
#define QUEUE 0
#define DELIM " \n\t\r\a\b"
#define FAILURE -1


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int call_line);
} instruction_t;

/**
 * struct global_s - global struct for monty variable
 * @err_status: error status to hold error term
 * @toks_num: number tokenized from the line read
 */
typedef struct global_s
{
	int err_status;
	char *toks_num;
} global_t;

extern global_t global;

int execute(FILE *l_file);
void (*get_op(char *ops))(stack_t **, unsigned int);
stack_t *stack_init(void);
int check_mode(stack_t *stack);

int is_dig(char *val);
int size_of_stack(stack_t *stack);
stack_t *add_new_node(int num);

void push_ops(stack_t **stack, unsigned int call_line);
void pall_ops(stack_t **stack, unsigned int call_line);
void pint_ops(stack_t **stack, unsigned int call_line);
void pop_ops(stack_t **stack, unsigned int call_line);
void swap_ops(stack_t **stack, unsigned int line_no);

void div_ops(stack_t **stack, unsigned int call_line);
void mul_ops(stack_t **stack, unsigned int call_line);
void mod_ops(stack_t **stack, unsigned int call_line);
void add_ops(stack_t **stack, unsigned int call_line);
void sub_ops(stack_t **stack, unsigned int call_line);

void pchar_ops(stack_t **stack, unsigned int call_line);
void pstr_ops(stack_t **stack, unsigned int call_line);
void rotb_ops(stack_t **stack, unsigned int call_line);
void rott_ops(stack_t **stack, unsigned int call_line);

void stack_ops(stack_t **stack, unsigned int call_line);
void queue_ops(stack_t **stack, unsigned int call_line);
void nop_ops(stack_t **stack, unsigned int call_line);

void free_stack(stack_t **stack);
#endif 

