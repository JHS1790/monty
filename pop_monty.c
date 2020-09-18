#include "monty.h"
/**
 * pop_monty - pops the first in the stack
 * @stack: the thing to do things to
 * @line_number: for error msg
 */
void pop_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *navigator = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_monty_stack(stack);
		exit(EXIT_FAILURE);
	}
	while (navigator->next)
		navigator = navigator->next;
	if (navigator->prev)
		navigator->prev->next = NULL;
	if (navigator->next == NULL && navigator->prev == NULL)
	{
		free(navigator);
		*stack = NULL;
	}
	else
		free(navigator);
}
