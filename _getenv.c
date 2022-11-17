#include "main.h"

/**
* _getenv - returns the enviroment variable
*
* @name: name of the variable.
*
* Return: the value of the enviroment variable
*.
*/
char *_getenv(char *name)
{
	char **t_env = NULL, *env = NULL, *path = NULL;
	int i = 0;

	t_env = getenv_list();
	if (t_env != NULL)
	{

		while (t_env[i] != NULL)
		{
			env = strtok(strdup(t_env[i]), "=");
			if (strcmp(env, name) == 0)
			{
				env = strtok(NULL, "=");

				path = strdup(env);
				break;
			}
			free(env);
			i++;
		}
	}

	return (path);
}

/**
* getenv_list - returns all the lists of
* the enviroment variables.
*
* Return: list of the enviroment variables
*
*/
char **getenv_list()
{
	char **env_list = NULL;

	env_list = move_envto_heapmem();

	return (env_list);
}
