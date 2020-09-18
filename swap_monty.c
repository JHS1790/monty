#include "monty.h"

/**
 * swap_monty -swaps the first and second in stack
 * @stack: the stack to swap in
 * @line_number: for error msg
 */
void swap_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *navigator = *stack;
	int hold;

	if (navigator == NULL ||
	    (navigator->next == NULL && navigator->prev == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_monty_stack(stack);
		exit(EXIT_FAILURE);
	}
	while (navigator->next)
		navigator = navigator->next;
	hold = navigator->n;
	navigator->n = navigator->prev->n;
	navigator->prev->n = hold;
}
