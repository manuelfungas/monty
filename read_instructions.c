#include "monty.h"

/**
 * process_line - Process a line of Monty bytecode
 * @line: The line to process
 * @line_number: The current line number
 * @stack: Pointer to the stack
 * @cmd: Array of available instructions
 *
 * Description: This function processes a line of Monty bytecode,
 *              extracts the opcode and its arguments (if any), and
 *              executes the corresponding instruction function.
 */

void process_line(char *line, unsigned int *line_number,
		stack_t **stack, instruction_t *cmd)
{
	char *opcode = strtok(ptr, " \t\n");

	if (opcode == NULL || opcode[0] == '#')
		return;

	bool found = false;

	for (int i = 0; cmd[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, cmd[i].opcode) == 0)
		{
			found = true;
			if (strcmp(opcode, "push") == 0)
			{
				char *value_str = strtok(NULL, " \t\n");

				if (value_str == NULL)
				{
					fprintf(stderr, "L%u: usage: push integer\n", *line_number);
					exit(EXIT_FAILURE);
				}
				int value = atoi(value_str);

				cmd[i].f(stack, value);
			}
			else
			{
				cmd[i].f(stack, *line_number);
			}
			break;
		}
	}
	if (!found)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", *line_number, opcode);
		exit(EXIT_FAILURE);
	}
	(*line_number)++;
}

/**
 * read_instructions - Read and process Monty bytecode instructions from a file
 * @stack: Pointer to the stack
 * @cmd: Array of available instructions
 *
 * Description: This function reads Monty bytecode instructions from a file,
 *              processes each instruction line by line, and executes
 *              the corresponding instruction function.
 */
void read_instructions(stack_t **stack, instruction_t *cmd)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;

	while ((read = getline(&line, &len, file)) != -1)
	{
		process_line(line, &line_number, stack, cmd);
	}
	free(line);
}
