#include "monty.h"
/**
*
*
*
*
*/
void mul_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *nav = *stack;

	while (nav->next != NULL)
		nav = nav->next;

	if (nav->prev == NULL)
	{
		fprintf(stderr, "L%d: can't multiply, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	nav->prev->n = nav->n * nav->prev->n;
	pop_monty(stack, line_number);
}
