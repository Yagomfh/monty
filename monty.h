#ifndef _MONTY_H
#define _MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global vars
 * @line: opcode line
 * @file: file descriptor
 * @format_data: queue or stack
 * Description: global variables to please betty
 */

typedef struct global_s
{
	char *line;
	FILE *file;
	char format_data;
} global_t;

global_t global;

/* check_opcode */
int function_check(char *opcode, unsigned int lc, stack_t **head);
int function_push(char *opcode, char *code, unsigned int lc, stack_t **head);

/** manage stack **/
void free_stack(stack_t *head);
stack_t *add_dnodeint(stack_t **head, int n);
size_t print_dlistint(const stack_t *h);
size_t stack_len(stack_t *h);
stack_t *add_dnodeint_end(stack_t **head, const int n);

/** opcode function **/
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _comment(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
#endif
