#include "monty.h"

void _pall(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	if (head != NULL)
		print_dlistint(head);
}
