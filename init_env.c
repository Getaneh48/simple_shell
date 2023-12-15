#include "main.h"

/**
* move_envto_heapmem - move an enviroment variable from
* a stack to the heap memory.
* Return: address of the enviroment variable.
*/
char **move_envto_heapmem()
{
	int len = 0, i = 0;
	char *env = NULL;

	if (environ_on_stack)
	{
		len = get_arrptr_length(environ);
		temp_environ = malloc((len + 1) * sizeof(char *));
		if (temp_environ != NULL)
		{
			while (environ[i] != NULL)
			{
				env = strdup(environ[i]);
				if (env)
				{
					temp_environ[i] = env;
				}
				i++;
			}
			temp_environ[i] = NULL;
			environ_on_stack = FALSE;
		}
		else
			dprintf(2, "Unable to allocate memory\n");
	}
	else
	{
		if (temp_environ == NULL)
		{
			environ_on_stack = TRUE;
			move_envto_heapmem();
		}
	}

	return (temp_environ);
}

/**
* get_arrptr_length - counts the length of array
* @arr: array
* Return: count.
*/
int get_arrptr_length(char **arr)
{
	int i = 0;

	if (arr != NULL)
	{
		for (i = 0; arr[i] != NULL; i++)
			;
	}
	else
		i = -1;

	return (i);
}
