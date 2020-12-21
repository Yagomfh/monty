#include "monty.h"

void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack != NULL)
		print_dlistint(*stack);
}
