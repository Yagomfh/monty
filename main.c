#include "monty.h"

/**
 * main - entry
 *
 *
 *
 */
int main(int ac, char **av)
{
	FILE *file;
	size_t len = 0;
	char *token, *code, *delim = " \n", *line = NULL;
	unsigned int line_count = 0;
	stack_t *head;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	head = NULL;
	while ((getline(&line, &len, file)) != -1)
	{
		token = strtok(line, delim);
		if (token == NULL || token[0] == '#')
		{
			line_count++;
			continue;
		}
		code = strtok(NULL, delim);
		line_count++;
		if (code == NULL && strcmp(token, "push") != 0)
		{
			if (function_check(token, line_count, &head) == -1)
			{
				free_stack(head);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (function_push(token, code, line_count, &head) == -1)
			{
				free_stack(head);
				exit(EXIT_FAILURE);
			}
		}
	}
	fclose(file);
	free(line);
	free_stack(head);
	return (0);
}
