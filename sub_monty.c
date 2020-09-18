#include "monty.h"
/**
* sub_monty - subtracts the firs form the second in stack
* @stack: stack to do stuff in
* @line_number: for error msg
*/
void sub_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *nav = *stack;

	while (nav->next != NULL)
		nav = nav->next;


	if (nav->prev == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short", line_number);
		free_monty_stack(stack);
		exit(EXIT_FAILURE);
	}
	nav->prev->n = nav->prev->n - nav->n;
	pop_monty(stack, line_number);
}
