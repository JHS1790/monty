#include "monty.h"
/**
* add_monty - adds the top of the stack and the second-in-stack
* @stack: to do the things with
* @line_number: for error msgs
*/
void add_monty(stack_t **stack, unsigned int line_number)
{
	int cur;

	while ((*stack)->next != NULL)
		(*stack) = (*stack)->next;
	cur = (*stack)->n;
	if ((*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n = cur + (*stack)->prev->n;
	pop_monty(stack, line_number);
}
