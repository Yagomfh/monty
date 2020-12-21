#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @stack: pointer to head of stack
 * @line_number: line number
 * Return: void
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _swap - swaps the top two elements of the stack
 * @stack: pointer to head of stack
 * @line_number: line number
 * Return: void
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	unsigned int len_s = stack_len(*stack);
	stack_t *current = *stack;
	int tmp;

	if (len_s < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = current->n;
	current->n = current->next->n;
	current->next->n = tmp;
}

/**
 * _nop - does nothing
 * @stack: pointer to head of stack
 * @line_number: line number
 * Return: void
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	return;
}
