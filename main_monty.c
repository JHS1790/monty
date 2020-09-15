#include "monty.h"

/**
 * main - an interpreter for Monty ByteCodes files
 * @argv: arguments vector - the arguments as an array of strings passed in
 * @argc: arguments count - how many arguments are passed in
 * Return: 0 on success, XX error codes
 */
int main(int argc, char **argv)
{
	char buffer[1024];
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	/* File is open*/

	fgets(buffer, 1024, file);
	printf("buffer:%s", buffer);

	fclose(file);
	/* File is closed*/

	exit (EXIT_SUCCESS);
}
