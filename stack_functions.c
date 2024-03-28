#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: Pointer to the stack
 * @line_number: Line number being executed
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *token = strtok(NULL, " \n");
	stack_t *new_node;

	if (!token || !is_digit(*token))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(token);
	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pop - Removes the top element of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number being executed
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = (*stack)->next;
	free(top);
}
/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number being executed
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}

