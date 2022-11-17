#include "main.h"

/**
* locate - search a command for its path.
* @cmd: command to be checked.
* Return: path of the command.
*/
char *locate(char *cmd)
{
	struct stat buf;
	char *path = NULL, *p = NULL, *filepath = NULL;
	int len = 0;

	if (stat(cmd, &buf) == 0)
		return (strdup(cmd));

	path = _getenv("PATH");
	if (path)
	{
		p = strtok(path, ":");
		while (p != NULL)
		{
			filepath = malloc(_strlen(p) + _strlen(cmd) + 2);
			if (filepath != NULL)
			{
				strcpy(filepath, p);
				if (p[strlen(p) - 1] != '/')
					_strcat(filepath, "/");
				_strcat(filepath, cmd);

				if (stat(filepath, &buf) == 0)
					return (filepath);
				free(filepath);
			}

			p = strtok(NULL, ":");
		}
	}

	return (NULL);
}
