#include "main.h"
/**
 * get_locat - get the path of the givin command
 * @cmd: command
 * Return: path
 */
char *get_locat(char *cmd)
{
	char *path, *path_cpy, *path_token, *file_path;
	int cmd_length, dir_length;
	struct stat buff;

	/*path = _getenv(info_st *info, "PATH");*/
	path = getenv("PATH");

	if (path)
	{
		path_cpy = _strdup(path);
		cmd_length = _strlen(cmd);
		path_token = strtok(path_cpy, ":");

		while (path_token != NULL)
		{
			dir_length = _strlen(path_token);
			file_path = malloc(cmd_length + dir_length + 2);

			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, cmd);
			_strcat(file_path, "\0");

			if (stat(file_path, &buff) == 0)
			{
				free(path_cpy);

				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_cpy);
		if (stat(cmd, &buff) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}
