#include "monty.h"
/**
* div_monty - divides the second by the first
* @stack: to do stuff in
* @line_number: for error msg
*/
void div_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *nav = *stack;

	while (nav->next != NULL)
		nav = nav->next;

	if (nav->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		free_monty_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (nav->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		free_monty_stack(stack);
		exit(EXIT_FAILURE);
	}
	nav->prev->n = nav->prev->n / nav->n;
	pop_monty(stack, line_number);
}
