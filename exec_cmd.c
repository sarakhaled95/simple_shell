#include "main.h"

/**
 * exe_cmd - responsible for handling command execution
 * argv = argument vector
 * Rerurn: void
 */

void exe_cmd(char **argv)
{
	char *cmd = NULL;

	if (argv)
	{
		cmd = argv[0];

		if (execve(cmd, argv,NULL) == -1)
		{
			perror("Error:");
		};
	}

}
