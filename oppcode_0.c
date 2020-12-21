#include "monty.h"

void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack != NULL)
		print_dlistint(*stack);
}
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE); /** check if -1 return in main to exit, EXIT_FAILURE **/
	}
	tmp = *stack;
	(*stack) = (*stack)->next;
	free(tmp);
}
void _add(stack_t **stack, unsigned int line_number)
{
	int length_s = stack_len(*stack), tmp_head = 0;
	stack_t *tmp;

	if (length_s < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp_head = (*stack)->n;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	(*stack)->n = (*stack)->n + tmp_head;
}
