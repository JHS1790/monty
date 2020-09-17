#include "monty.h"
/**
* pint_monty - prints the top of the stack
* @stack: the stack to print from
* @line_number: for if it fails
*/
void pint_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *nav = *stack;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L <%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (nav->next != NULL)
	{
		nav = nav->next;
	}
	printf("%d\n", nav->n);
}
