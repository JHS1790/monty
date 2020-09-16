#include "monty.h"

/**
 * push_monty - pushes item held in global_token_int to the stack
 * @stack: the stack we're pushing to
 * @line_number: line number of opcode call
 */
void push_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = malloc(sizeof(stack_t)), *navigator = *stack;

	(void)line_number;
	/*printf("Push function successfully called!\n");*/
	if (!newnode)
	{
		perror("");
		return;
	}
	newnode->next = NULL;
	newnode->n = global_token_int;
	/*printf("Newnode successfully formed!\n");*/
	if (!*stack)
	{
		newnode->prev = NULL;
		*stack = newnode;
	}
	else
	{
		while(navigator->next)
			navigator = navigator->next;
		navigator->next = newnode;
		newnode->prev = navigator;
	}
}
