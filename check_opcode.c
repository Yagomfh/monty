#include "monty.h"

int function_check(char *opcode, int lc)
{
	int i = 0;

	instruction_t ops[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	while(ops[i].opcode)
	{
		if (!strcmp(opcode, ops[i].opcode))
		{
			ops[idx].f(&stack, lc);
			break;
		}
	}
	if (ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lc, opcode);
		return (-1);
	}
	return (0);
}
int check_opcode(char *opcode, char *code, int lc)
{
	if (strcmp("push", opcode) != 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lc, opcode);
		return (-1);
	}
	if (atoi(code) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", lc);
	}
	return (0);
}

