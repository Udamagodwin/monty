#include "monty.h"


global_t global = {EXIT_SUCCESS, NULL};

/**
 * main - Entry point for monty interpreter
 *
 * @argc: arguement count
 * @argv: An array arguements to be passed
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[])
{
	FILE *fd = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");

	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	global.err_status = execute(fd);
	fclose(fd);

	exit(global.err_status);
}

