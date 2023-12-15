#include "main.h"

/**
* locate - search a command for its path.
* @cmd: command to be checked.
* Return: path of the command.
*/
char *locate(char *cmd)
{
	struct stat buf;
	char *path = NULL, **p = NULL, *filepath = NULL, *str;
	int i = 0;

	if (stat(cmd, &buf) == 0)
		return (strdup(cmd));

	path = _getenv("PATH");
	if (path)
	{
		p = tokenize(path, ':');
		free(path);
		while (p[i] != NULL)
		{
			str = p[i];
			filepath = malloc(_strlen(str) + _strlen(cmd) + 2);
			if (filepath != NULL)
			{
				strcpy(filepath, str);
				if (str[strlen(str) - 1] != '/')
					_strcat(filepath, "/");
				_strcat(filepath, cmd);

				if (stat(filepath, &buf) == 0)
				{
					free_memory(p);
					return (filepath);
				}
				free(filepath);
			}

			/*p = strtok(NULL, ":");*/
			i++;
		}
		free_memory(p);
	}

	return (NULL);
}
