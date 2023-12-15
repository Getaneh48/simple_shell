#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "main.h"

/**
* read_command_file - reads a command from a given file
* and executes them.
*
* @filename: file containing commands.
* @appname: the name of the application.
* Return: 0 on success -1 on failor
*/
int read_command_file(char *filename, char *appname)
{
	int fd, i = 0;
	char *buffer, **tokens, *tbuf;
	struct stat stats;

	if (stat(filename, &stats) == -1)
	{
		dprintf(2, "%s: 0: Can't open %s\n", appname, filename);
		return (-1);
	}

	fd = open(filename, O_RDONLY);
	tbuf = malloc(sizeof(char));
	buffer = malloc(1024);
	while (read(fd, tbuf, 1))
	{
		if (tbuf[0] == '\n')
		{
			buffer[i] = '\0';
			tokens = _strtoken(buffer);
			if (tokens != NULL)
			{
				handleCommand(appname, tokens);
				free_memory(tokens);
			}
			i = 0;
			/*free(buffer);*/
			buffer = malloc(1024);
		}
		else
		{
			buffer[i] = tbuf[0];
			i++;
		}
	}
	free(tbuf);
	if (buffer != NULL)
		free(buffer);
	close(fd);
	return (0);
}
