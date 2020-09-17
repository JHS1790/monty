#include "monty.h"
/**
 * check_token_int - checks the token_int to makesure its a int
 * @token_int: the token to contain an int
 * Return: 0 or 1
 */
int check_token_int(char *token_int)
{
	unsigned int i;

	/*printf("Entered check_token_int");*/
	for (i = 0; i < strlen(token_int); i++)
	{
		if (!(token_int[i] >= '0' && token_int[i] <= '9'))
		return (1);
	}
	return (0);
}
/**
 * free_monty_stack - frees montys stack
 * @stack: the stack to be freed
 */
void free_monty_stack(stack_t **stack)
{
	stack_t *navigator;

	if (*stack)
	{
		while ((*stack)->next)
			*stack = (*stack)->next;
		while ((*stack)->prev)
		{
			navigator = *stack;
			*stack = (*stack)->prev;
			free(navigator);
		}
		free(*stack);
	}
	free(stack);
}
