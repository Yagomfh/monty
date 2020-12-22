#include "monty.h"

/**
 * function_check - check if oppcode exist and launch
 * @opcode: the opcode to check
 * @lc: number of the line of the command
 * @head: the stack
 * Return: -1 if error, 0 otherwise
 */
int function_check(char *opcode, unsigned int lc, stack_t **head)
{
	int i = 0, idx = 0;

	instruction_t ops[] = {
		{"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap},
		{"add", _add}, {"nop", _nop},
		{"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr}, {"rotl", _rotl},
		{"rotr", _rotr}, {"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	while (ops[i].opcode)
	{
		if (!strcmp(opcode, ops[i].opcode))
		{
			ops[idx].f(head, lc);
			break;
		}
		idx++;
		i++;
	}
	if (ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lc, opcode);
		return (-1);
	}
	return (0);
}
/**
 * function_push - check if push and if so, push to the stack
 * @opcode: the opcode to check
 * @code: arg to opcode
 * @lc: number of the line of the command
 * @head: the stack
 * Return: -1 if error, 0 otherwise
 */
int function_push(char *opcode, char *code, unsigned int lc, stack_t **head)
{
	int i = 0, nb_code = 0;

	if (strcmp("push", opcode) != 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lc, opcode);
		return (-1);
	}
	if (code == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", lc);
		return (-1);
	}
	while (code[i])
	{
		if (code[i] < 48 && code[i] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", lc);
			return (-1);
		}
		i++;
	}
	nb_code = atoi(code);
	if (global.format_data == 's')
	{
		if (add_dnodeint(head, nb_code) == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			return (-1);
		}
	}
	else
	{
		if (add_dnodeint_end(head, nb_code) == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			return (-1);
		}
	}
	return (0);
}

