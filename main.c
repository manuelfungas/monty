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
	if (argc != c)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);


	return (0);
}