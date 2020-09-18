#include "monty.h"

/**
 * push_monty - pushes item held in global_token_int to the stack
 * @stack: the stack we're pushing to
 * @line_number: line number of opcode call
 */
void push_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = malloc(sizeof(stack_t));
	stack_t *navigator = *stack;


	if (!newnode)
	{
		perror("");
		return;
	}
	newnode->next = NULL;
	if (global_variables->n)
		newnode->n = *(global_variables->n);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(newnode);
		free_monty_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (!*stack)
	{
		newnode->prev = NULL;
		*stack = newnode;
	}
	else
	{
		while (navigator->next)
			navigator = navigator->next;
		navigator->next = newnode;
		newnode->prev = navigator;
	}
}
