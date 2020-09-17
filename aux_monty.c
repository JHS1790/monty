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
 */
void free_monty_stack()
{
	stack_t *navigator, *stack = *(global_variables->stack);
	char *buffer = *(global_variables->buffer);
	int *n = *(global_variables->n);

	if (stack)
	{
		while (stack->next)
			stack = stack->next;
		while (stack->prev)
		{
			navigator = stack;
			stack = stack->prev;
			free(navigator);
		}
		free(stack);
	}
	if (n)
		free(n);
	free(buffer);
	free(global_variables->n);
	free(global_variables->buffer);
	free(global_variables->stack);
	free(global_variables);
}
