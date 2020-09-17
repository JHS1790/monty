#include "monty.h"
global_t *global_variables;
/**
 * main - an interpreter for Monty ByteCodes files
 * @argv: arguments vector - the arguments as an array of strings passed in
 * @argc: arguments count - how many arguments are passed in
 * Return: 0 on success, XX error codes
 */
int main(int argc, char **argv)
{
	char *buffer = malloc(1024), *token_opcode, *token_int;
	unsigned int line_number = 0;
	FILE *file;
	stack_t *stack = NULL;

	global_variables = malloc(sizeof(global_t));
	if (buffer == NULL || global_variables == NULL)
		error_monty(3, &stack, NULL);
	global_variables->buffer = &buffer;
	if (argc != 2)
		error_monty(1, &stack, NULL);
	file = fopen(argv[1], "r");
	global_variables->file = &file;
	if (file == NULL)
		error_monty(2, &stack, argv[1]);
	while (fgets(buffer, 1024, file))
	{
		line_number++;
		token_opcode = strtok(buffer, " \n");
		if (token_opcode)
		{
			if (!strcmp(token_opcode, "push"))
				token_int = strtok(NULL, " \n");
			else
				token_int = NULL;
			check_opcode(&stack, line_number, token_opcode, token_int);
		}
	}
	free_monty_stack(&stack);
	exit(EXIT_SUCCESS);
}
/**
 * check_opcode - checks the token if its an opcode
 * @stack: the stack to be passed if opcode
 * @line_number: the line number for error
 * @token_opcode: the opcode hopefully
 * @token_int: to be turned into a global variable
 * Return: 1 on success or 0 on failure
 */
int check_opcode(stack_t **stack, unsigned int line_number,
char *token_opcode, char *token_int)
{
	int i, *n = malloc(sizeof(int *));
	instruction_t ops[] = {
		{"push", &push_monty},
		{"pall", &pall_monty},
		{"pint", &pint_monty},
		{"pop", &pop_monty},
		{"swap", &swap_monty},
		{"nop", &nop_monty},
		{"#", &nop_monty},
		{"add", &add_monty},
		{NULL, NULL} };

	insert_int(token_int, n);

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if ((!strcmp(token_opcode, ops[i].opcode)) || token_opcode[i] == '#')
		{
			ops[i].f(stack, line_number);
			global_variables->n = NULL;
			free(n);
			return (0);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token_opcode);
	if (n)
		free(n);
	free_monty_stack(stack);
	exit (EXIT_FAILURE);
}
