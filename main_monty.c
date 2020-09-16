#include "monty.h"
int global_token_int;
/**
 * main - an interpreter for Monty ByteCodes files
 * @argv: arguments vector - the arguments as an array of strings passed in
 * @argc: arguments count - how many arguments are passed in
 * Return: 0 on success, XX error codes
 */
int main(int argc, char **argv)
{
	char buffer[1024], *token_opcode, *token_int;
	unsigned int line_number = 0;
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	/* File is open*/

	while (fgets(buffer, 1024, file))
	{
		/*Reading file line by line*/
		line_number++;
		token_opcode = strtok(buffer, " \n");
		if (!strcmp(token_opcode, "push"))
			token_int = strtok(NULL, " \n");
		else
			token_int = NULL;
		/*printf("opcode:%s || data:%s\n", token_opcode, token_int);*/
		check_opcode(stack, line_number, token_opcode, token_int);
	}

	fclose(file);
	/* File is closed*/

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
int check_opcode(stack_t *stack, unsigned int line_number,
char *token_opcode, char *token_int)
{
	int i;
	instruction_t ops[] = {
			{"push",/* *blah*/},
			{"pall", /*bleh*/},
			{"pint", /*blih*/},
			{"pop", /*bloh*/},
			{"swap", /*bluh*/},
			{"add", /*blyh8*/},
			{"nop", /*ran out of nouns*/},
			{NULL, /*NULL*/} };

	if (token_int)
		global_token_int = atoi(token_int);
	(void)stack;
	(void)line_number;
	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (!strcmp(token_opcode, ops[i].opcode))
		{
			printf("success fuckface\n");
			return (1);
		}
	}

	return (0);
}
