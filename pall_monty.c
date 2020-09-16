#include "monty.h"

/**
 * pall_monty - prints all elements on the stack
 * @stack: the stack to print
 * @line_number: the line number the opcode was called on
 */
void pall_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *navigator = *stack;

	(void)line_number;
	if (!*stack)
		return;
	while(navigator->next)
		navigator = navigator->next;
	while(navigator->prev)
	{
		printf("%d\n", navigator->n);
		navigator = navigator->prev;
	}
	printf("%d\n", navigator->n);
}
