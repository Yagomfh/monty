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
	int line_count = 0;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (fopen(av[1], "r") == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");	
	while ((getline(&line, &len, file)) != -1)
	{
		token = strtok(line, delim);
		if (token == NULL)
		{
			line_count++;
			continue;
		}
		code = strtok(NULL, delim);
		line_count++;
		if (code != NULL)
			function_push(token, line_count);
		else
			function_check(token, code, line_count);
	}
	free(line);
	fclose(file);
	return (0);
}
