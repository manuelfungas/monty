#include "monty.h"
/**
 * is_digit - Check for a digit (0-9)
 * @c: Integer holding the character
 *
 * Return: 1 on success and 0 on failure
 */

int is_digit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);

	return (0);
}
