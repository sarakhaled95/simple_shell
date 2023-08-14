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
	char *line_ptr = NULL, *line_ptr_cpy = NULL;
	size_t i = 0;
	ssize_t numchar;
	const char *delim = " \n";
	int n_token = 0, n;
	char *token;
	(void)ac;

	while (1)
	{
		printf("%s", prompt);
		numchar = getline(&line_ptr, &i, stdin);
			if (numchar == -1)
			{
				printf("Exiting shell \n");
				return (-1);
			}
		line_ptr_cpy = malloc(sizeof(char) * numchar);
		if (line_ptr_cpy == NULL)
		{
			perror("memory allocation error");
			return (-1);
		}
		_strcpy(line_ptr_cpy, line_ptr);
		token = strtok(line_ptr, delim);
		while (token != NULL)
		{
			n_token++;
			token = strtok(NULL, delim);
		}`
		n_token++;
		argv = malloc(sizeof(char *) * n_token);
		token = strtok(line_ptr_cpy, delim);/* storing each token in the argv array*/
		for (n = 0; token != NULL; n++)
		{
			argv[n] = malloc(sizeof(char) * strlen(token));
			_strcpy(argv[n], token);
			token = strtok(NULL, delim);
		}
		argv[n] = NULL;
		exe_cmd(argv);
	}
		free(line_ptr_cpy); /* free up all  allocated memory */
		free(line_ptr);
	return (0);
}
