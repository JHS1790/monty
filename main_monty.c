#include "monty.h"
int *global_token_int;
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
	stack_t **stack = malloc(sizeof(stack_t*));

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	*stack = NULL;
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can\'t open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
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
			check_opcode(stack, line_number, token_opcode, token_int);
		}
	}
	fclose(file);
	free(buffer);
	free_monty_stack(stack);
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
	int i, token_check;
	instruction_t ops[] = {
		{"push", &push_monty},
		{"pall", &pall_monty},
		/*{"pint", &pint_monty},
		{"pop", &pop_monty},
		{"swap", &swap_monty},
		{"add", &add_monty},
		{"nop", &nop_monty},*/
		{NULL, NULL} };

	/*printf("Successfully entered check_opcode\n");*/
	if (token_int)
	{
		global_token_int = malloc(sizeof(int*));
		/*printf("Entered token_int check\n");*/
		token_check = check_token_int(token_int);
		/*printf("token_check = %d\n", token_check);*/
		if (token_check == 0)
		{
			*global_token_int = atoi(token_int);
		}
		else
			global_token_int = NULL;
	}
	else
		global_token_int = NULL;
	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (!strcmp(token_opcode, ops[i].opcode))
		{
			/*printf("Success! Opcode pulled: %s\n", ops[i].opcode);*/
			ops[i].f(stack, line_number);
			break;
		}
	}
	free(global_token_int);
	/*printf("Mission failed, we'll get 'em next time\n");*/
	return (0);
}
