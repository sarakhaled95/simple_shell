#include "main.h"
/**
 * _current_env - prints the current env
 * @info: structure
 * Return: Always 0
 */
int _current_env(info_st *info)
{
	print_liststr(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: structure
 * @name: enviroment variable name
 * Return: env value
 */
char *_getenv(info_st *info, const char *name)
{
	list_st *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_environ - returns the string array copy of our environ
 * @info: struct
 * Return: environ
 */
char **get_environ(info_st *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}
