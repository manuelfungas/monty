#include "monty.h"

/**
 * main - where it all happens
 *
 * @argc: number of args
 * @argv: value of args
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1], &stack);

	free_dlistint(stack);

	return (0);
}
