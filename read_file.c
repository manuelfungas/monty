#include "monty.h"

/**
 * read_file - Read a Monty bytecode file and execute its instructions
 * @filename: Name of the file to read
 * @stack: Pointer to the stack
 */
void read_file(char *filename, stack_t **stack)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	FILE *file = fopen(filename, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	
	read = getline(&line, &len, file); 
	while (read != -1)
	{
		char *opcode = parse_line(line);

		instruct_func func = get_op_function(opcode);

		if (func)
			func(stack, 0);
	}

	free(line);
	fclose(file);
}

/**
 * parse_line - Parse a line from a Monty bytecode file
 * @line: The line to parse
 *
 * Return: Opcode of the instruction
 */
char *parse_line(char *line)
{
	char *opcode;
	char *token;

	while (isspace(*line))
		line++;

	if (*line == '\0' || *line == '#')
		return (NULL);

	token = strtok(line, " \t\n");

	if (token == NULL)
		return (NULL);

	opcode = malloc(strlen(token) + 1);
	if (opcode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	strcpy(opcode, token);

	return (opcode);
}

/**
 * get_op_function - Get the function pointer for an opcode
 * @str: The opcode to search for
 *
 * Return: Pointer to the function corresponding to the opcode
 */
instruct_func get_op_function(char *str)
{
	int i;

	instruction_t op_functions[] = {
		{"push", &push},
		{"pop", &pop},
		{"add", &add},
		{"pall", &pall},
		{"swap", &swap},
		{"nop", &nop},
		{NULL, NULL}
	};

	for (i = 0; op_functions[i].opcode != NULL; i++)
	{
		if (strcmp(str, op_functions[i].opcode) == 0)
			return (op_functions[i].f);
	}

	return (NULL);
}

