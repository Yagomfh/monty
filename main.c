#include "monty.h"

/**
 * launch_oppcode - check and call function
 * @t: oppcode token
 * @f: file descriptor
 * @code: argument to oppcode
 * @lc: number of the line of the command
 * @h: stack
 * Return: nothing or exit if error
 */
int launch_oppcode(char *t, FILE *f, char *code, unsigned int lc, stack_t **h)
{
	if (strcmp(t, "push") != 0)
	{
		if (function_check(t, lc, h) == -1)
		{
			free_stack(*h);
			fclose(f);
			return (-1);
		}
	}
	else
	{
		if (function_push(t, code, lc, h) == -1)
		{
			free_stack(*h);
			fclose(f);
			return (-1);
		}
	}
	return (0);
}

/**
 * main - entry
 * @ac: nb of args
 * @av: arguments
 * Return: exit if error, 0 otherwise
 */
int main(int ac, char **av)
{
	FILE *file;
	size_t len = 0;
	char *token, *code, *delim = " \n\t", *line = NULL;
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
		exit(EXIT_FAILURE);
	}
	head = NULL, format_data = 's';
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
		if (launch_oppcode(token, file, code, line_count, &head) == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	free(line);
	free_stack(head);
	return (0);
}
