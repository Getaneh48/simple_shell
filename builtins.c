#include "main.h"

/**
* _env - handles the 'env' command.
*
* @appname: the application name
* @tokens: lists of arguments.
*
* Return: 1 for error 0 for success.
*/
int _env(char *appname __attribute__((unused)), char **tokens)
{
	int i = 0;
	char **t_env = NULL;

	if (tokens[i + 1] != NULL)
	{
		dprintf(2, "%s: '%s': No such file or directory\n", tokens[0], tokens[1]);
		return (1);
	}
	else
	{
		if (environ_on_stack)
			t_env = environ;
		else
			t_env = temp_environ;

		while (t_env[i] != NULL)
		{
			printf("%s\n", t_env[i]);
			i++;
		}
	}
	return (0);
}

/**
* _setenv - sets an enviroment variable.
*
* @appname: the application name
* @tokens: lists of arguments.
*
* Return: 1 for error 0 for success.
*/
int _setenv(char *appname __attribute__((unused)), char **tokens)
{
	char *ev = NULL;

	ev = _getenv(tokens[1]);
	if (ev != NULL)
	{
		replace_env(tokens);
	}
	else
	{
		/* env variable doesn't exist. */
		new_env(tokens);
	}

	return (0);
}

/**
* _unsetenv - removes an enviroment variable.
*
* @appname: the application name
* @tokens: lists of arguments.
*
* Return: -1 for error 0 for success.
*/
int _unsetenv(char *appname __attribute__((unused)), char **tokens)
{
	int i = 0;

	for (i = 0; tokens[i] != NULL; i++)
		;
	if (i == 2)
		remove_env(tokens);
	else
	{
		dprintf(2, "%s: invalid argument\n", tokens[0]);
		return (-1);
	}
	return (0);
}

/**
* _cd - handles changing a working directory.
*
* @appname: the application name
* @tokens: lists of arguments.
*
* Return: -1 for error 0 for success.
*/
int _cd(char *appname __attribute__((unused)), char **tokens)
{
	int i = 0;

	for (i = 0; tokens[i] != NULL; i++)
		;
	if (i == 1)
	{
		if (change_dir(tokens[0]) == 0)
			return (0);

		return (-1);
	}
	else if (i == 2)
	{
		if (change_dir(tokens[1]) == 0)
			return (0);

		dprintf(2, "%s: 1: %s: can't cd to %s\n", appname, tokens[0], tokens[1]);
		return (-1);
	}
	else
	{
		dprintf(2, "%s: 1: %s: can't cd to %s\n", appname, tokens[0], tokens[1]);
		return (-1);
	}

	return (0);
}

/**
* _alias - handles alias command.
*
* @appname: the application name
* @tokens: lists of arguments.
*
* Return: -1 for error 0 for success.
*/
int _alias(char *appname __attribute__((unused)), char **tokens)
{
	handle_alias(tokens);

	return (0);
}
