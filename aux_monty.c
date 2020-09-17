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
void free_monty_stack(stack_t **stack)
{
	stack_t *navigator;
/*	char *buffer = *(global_variables->buffer);
 *	int *n = *(global_variables->n);
 */
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
	if (global_variables->n)
		free(global_variables->n);
	free(*global_variables->buffer);
	if (*global_variables->file)
		fclose(*global_variables->file);
	free(global_variables);
}
/**
 *
 */
void error_monty(int errorcode, stack_t **stack, char *file)
{
	switch (errorcode)
	{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
		free_monty_stack(stack);
		exit(EXIT_FAILURE);
	case 2:
		fprintf(stderr, "Error: Can\'t open file %s\n", file);
		free_monty_stack(stack);
		exit(EXIT_FAILURE);
	case 3:
		fprintf(stderr, "Error: malloc failed\n");
		free_monty_stack(stack);
		exit(EXIT_FAILURE);
	}
}
/**
*
*
*
*/
void insert_int(char *token_int, int *n)
{
	int token_check;
	if (token_int)
	{
		/*printf("Entered token_int check\n");*/
		token_check = check_token_int(token_int);
		/*printf("token_check = %d\n", token_check);*/
		if (token_check == 0)
		{
			*n = atoi(token_int);
			global_variables->n = n;
			/*printf("global n:%i\n", *(global_variables->n));*/
		}
		else
		{
			global_variables->n = NULL;
			free(n);
		}
	}
	else
		global_variables->n = NULL;
}
