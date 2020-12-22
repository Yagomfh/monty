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
		free(global.line), fclose(global.file);
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
		free(global.line), fclose(global.file);
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

	/**return;**/
}

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack
 * @stack: pointer to head of stack
 * @line_number: line number
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	unsigned int len_s = stack_len(*stack);
	stack_t *current = *stack, *next;

	if (len_s < 2)
	{
		free(global.line), fclose(global.file);
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		free(global.line), fclose(global.file);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = current->next;
	next->n /= current->n;
	*stack = next;
	free(current);
}

/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: pointer to head of stack
 * @line_number: line number
 * Return: void
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	unsigned int len_s = stack_len(*stack);
	stack_t *current = *stack, *next;

	if (len_s < 2)
	{
		free(global.line), fclose(global.file);
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		free(global.line), fclose(global.file);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = current->next;
	next->n %= current->n;
	*stack = next;
	free(current);
}
