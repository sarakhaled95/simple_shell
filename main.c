#include "main.h"
/**
 * main - the main function of shell
 * @ac: argument count
 * @argv: argument vector
 * Return: 0 on success 1 for fail
 */

int main(int ac, char **argv)
{
	char *prompt = "(shell) $ ";

	char *line_ptr;

	size_t i = 0;

	(void)ac;
	(void)argv;

	printf("%s", prompt);
	getline(&line_ptr, &i, stdin);
	printf("%s\n", line_ptr);

	free(line_ptr);
	return (0);
}
