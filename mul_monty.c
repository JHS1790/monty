#include "monty.h"
/**
* mul_monty - multiplies the first and second
* @stack: to multiply in
* @line_number: for error msg
*/
void mul_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *nav = *stack;

	while (nav->next != NULL)
		nav = nav->next;

	if (nav->prev == NULL)
	{
		fprintf(stderr, "L%d: can't multiply, stack too short", line_number);
		free_monty_stack(stack);
		exit(EXIT_FAILURE);
	}
	nav->prev->n = nav->n * nav->prev->n;
	pop_monty(stack, line_number);
}
