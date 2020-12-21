#include "monty.h"

int function_check(char *opcode, unsigned int lc)
{
	int i = 0, idx = 0;

	instruction_t ops[] = {
		{"pall", _pall},
/**		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},*/
		{NULL, NULL}
	};

	while(ops[i].opcode)
	{
		if (!strcmp(opcode, ops[i].opcode))
		{
			ops[idx].f(&head, lc);
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
int function_push(char *opcode, char *code, unsigned int lc)
{
	int i = 0, is_char = 0, nb_code = 0;

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
		if (isdigit(code[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", lc);
			return (-1);
		}
		i++;
	}
	nb_code = atoi(code);
	add_dnodeint(&head, nb_code);
	return (0);
}

