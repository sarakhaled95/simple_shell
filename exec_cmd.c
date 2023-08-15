#include "main.h"

/**
 * exe_cmd - responsible for handling command execution
 * @argv: argument vector
 * Rerurn: void
 */

void exe_cmd(char **argv)
{
	char *cmd = NULL, *actual_cmd = NULL;

	if (argv)
	{
		cmd = argv[0];

		actual_cmd = get_location(char *cmd);

		if (execve(actual_cmd, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}

}
