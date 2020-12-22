#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack
 * @stack: pointer to head of stack
 * @line_number: line number
 * Return: void
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * _rotl - rotates the stack to the top
 * @stack: pointer to head of stack
 * @line_number: line number
 * Return: void
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	unsigned int len_s = stack_len(*stack);
	stack_t *current = *stack, *next;
	int tmp;

	(void)line_number;

	if (len_s < 2)
		return;

	tmp = current->n;
	next = current->next;
	*stack = next;
	free(current);
	if (add_dnodeint_end(stack, tmp) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * _stack - initialize global var to stack
 * @stack: pointer to head of stack
 * @line_number: line number
 * Return: void
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;

	format_data = 's';
}
/**
 * _queue - initialize global var to queue
 * @stack: pointer to head of stack
 * @line_number: line number
 * Return: void
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	format_data = 'q';
}
