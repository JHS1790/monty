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
		exit (EXIT_FAILURE);
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

	exit (EXIT_SUCCESS);
}

/**
 *
 *
 * BETTY
 *
 *
 */
int check_opcode(stack_t *stack, unsigned int line_number, char *token_opcode, char *token_int)
{
	if (token_int)
		global_token_int = atoi(token_int);

	printf("global token = %d\n", global_token_int);

	(void)stack;
	(void)line_number;
	(void)token_opcode;

	return (0);
}
