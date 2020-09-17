#include "monty.h"

/**
 * swap_monty -
 * @stack:
 * @line_number:
 */
void swap_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *navigator = *stack;
	int hold;

	if (navigator == NULL ||
	    (navigator->next == NULL && navigator->prev == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit (EXIT_FAILURE);
	}
	while (navigator->next)
		navigator = navigator->next;
	hold = navigator->n;
	navigator->n = navigator->prev->n;
	navigator->prev->n = hold;
}
