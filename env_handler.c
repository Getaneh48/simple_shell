#include "main.h"

/**
* duplicate_environ - duplicates the enviroment variable
* from the stack to the heap memory.
*
* @tokens: array of arguments.
*
* Return: pointer to the location of the enviroment variable list.
*/
char **duplicate_environ(char **tokens)
{
	char **t_env = NULL;
	int i = 0, k = 0;

	tokens = tokens;
	if (environ_on_stack)
		t_env = environ;
	else
		t_env = temp_environ;

	for (i = 0; t_env[i] != NULL; i++)
		;

	temp_environ = (char **)malloc((i + 2) * sizeof(char *));
	if (temp_environ == NULL)
		return (NULL);

	for (i = 0; t_env[i] != NULL; i++)
	{
		temp_environ[k] = strdup(t_env[i]);
		k++;
	}

	temp_environ[k] = NULL;
	if (environ_on_stack == FALSE)
		free_memory(t_env);

	return (temp_environ);
}

/**
* new_env - adds a new enviroment variable to the list.
*
* @tokens: array of args.
* Return: 0 success 1 error.
*/
int new_env(char **tokens)
{
	char *str = NULL;
	int i = 0;

		if (environ_on_stack)
		{
			if (duplicate_environ(tokens))
				environ_on_stack = FALSE;

			for (i = 0; temp_environ[i] != NULL; i++)
				;
			str = malloc(strlen(tokens[1]) + strlen(tokens[2]) + 2);
			if (str)
			{
				strcpy(str, tokens[1]);
				_strcat(str, "=");
				_strcat(str, tokens[2]);
				temp_environ[i] = str;
				temp_environ[i + 1] = NULL;
			}
		}
		else
		{
			if (duplicate_environ(tokens) == NULL)
			{
				environ_on_stack = TRUE;
				return (1);
			}
			for (i = 0; temp_environ[i] != NULL; i++)
				;
			str = malloc(strlen(tokens[1]) + strlen(tokens[2]) + 2);
			if (str)
			{
				strcpy(str, tokens[1]);
				strcat(str, "=");
				strcat(str, tokens[2]);
				temp_environ[i] = str;
				temp_environ[i + 1] = NULL;
			}
		}
	return (0);
}

/**
* replace_env - replaces an enviroment variable from the list.
*
* @tokens: array of args.
* Return: 0 success 1 error.
*/
int replace_env(char **tokens)
{
	char *str = NULL;
	int i = 0;

	if (environ_on_stack)
	{
		if (duplicate_environ(tokens) == NULL)
		{
			perror("error duplicating environ\n");
			return (1);
		}
		environ_on_stack = FALSE;
	}
	while (temp_environ[i] != NULL)
	{
		if (strncmp(temp_environ[i], tokens[1], _strlen(tokens[1])) == 0)
		{
			str = malloc(strlen(tokens[1]) + strlen(tokens[2]) + 2);
			if (str)
			{
				strcpy(str, tokens[1]);
				_strcat(str, "=");
				_strcat(str, tokens[2]);
				temp_environ[i] = str;
			}
			break;
		}
		i++;
	}

	if (str == NULL)
		return (-1);

	return (0);
}

/**
* remove_env - removes an enviroment variable from the list.
*
* @tokens: array of args.
* Return: 0 success 1 error.
*/
int remove_env(char **tokens)
{
	int i = 0, k = 0;

	if (environ_on_stack)
	{
		if (duplicate_environ(tokens) == NULL)
		{
			perror("error duplicating environ\n");
			return (1);
		}
		environ_on_stack = FALSE;
	}

	for (i = 0; temp_environ[i] != NULL; i++)
	{
		if (strncmp(temp_environ[i], tokens[1], _strlen(tokens[1])) == 0)
		{
			for (k = i; temp_environ[k] != NULL; k++)
				temp_environ[k] = temp_environ[k + 1];

			break;
		}
	}

	return (0);
}
