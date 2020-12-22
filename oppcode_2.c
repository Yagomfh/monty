#include "monty.h"

/**
 * _pstr - transform int into ascii char
 * @stack: linked list
 * @line_number: number of the line of the command
 * Return: nothing
 *
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	/**int length_s = stack_len(*stack);**/
	stack_t *head = *stack;

	(void)line_number;
	while (head != NULL)
	{
		if (isascii(head->n) == 0 || head->n == 0)
			break;
		printf("%c", head->n);
		head = head->next;
	}
	printf("\n");
}
/**
 * _rotr - rotates the stack to the bottom
 * @stack: linked list
 * @line_number: number of the line of the command
 * Return: nothing
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	unsigned int len_s = stack_len(*stack);
	stack_t *delet, *current = *stack;
	int tmp;

	(void)line_number;

	if (len_s < 2)
		return;
	while (current->next)
		current = current->next;
	current->prev->next = NULL;
	tmp = current->n;
	delet = current;
	current = current->prev;
	free(delet);
	if (add_dnodeint(stack, tmp) == NULL)
	{
		free(global.line), fclose(global.file);
		free_stack(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
