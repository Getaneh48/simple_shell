#include "main.h"
#include "global_var.h"
#include <stdio.h>

/**
* checkBuiltinCmd - check if the command is a builtin command.
* @cmd: command string.
* Return: > 0 for success -1 failer.
*/
int checkBuiltinCmd(char *cmd)
{
	unsigned int index = -1, i = 0;

	while (builtins[i] != NULL)
	{
		if (_strcmp(cmd, builtins[i]) == 0)
		{
			index = i;
			break;
		}
		i++;
	}

	return (index);
}

/**
* execute_external_command - execute an external command.
* @filepath: string.
* @tokens: array of arguments.
* Return: 0 for success -1 failer.
*/
int execute_external_command(char *filepath, char **tokens)
{
	pid_t pid;
	int status = 0;

	if (filepath)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("unable create a child process\n");
			status = 1;
		}
		else if (pid == 0)
		{
			printf("%s\n", filepath);
			if (execve(filepath, tokens, environ) == -1)
			{
				perror("command not found\n");
				status = 1;
			}
		}
		else
			wait(NULL);
	}
	else
	{
		perror("command not found\n");
		status = 1;
	}

	return (status);
}

/**
* runCommand - runs a command.
* @appname: the application name
* @tokens: array of strings.
* Return: 0 for success 1 failer.
*/
int runCommand(char *appname, char **tokens)
{
	int builtin = 0, status __attribute__((unused));
	char *cmdpath = NULL;

	if (tokens != NULL)
	{
		builtin = checkBuiltinCmd(tokens[0]);
		if (builtin != -1)
		{
			builtin_func[builtin](appname, tokens);
			return (0);
		}
		else
		{
			cmdpath = locate(tokens[0]);
			if (cmdpath)
			{
				status = execute_external_command(cmdpath, tokens);
				free(cmdpath);
			}
			else
				printf("%s: 1: %s: not found\n", appname, tokens[0]);

			return (1);
		}
	}

	return (1);
}

/**
* handleCommand - runs a command
* @appname: the application name
* @tokens: array of strings.
* Return: status of a command.
*/
int handleCommand(char *appname, char **tokens)
{
	size_t status = 0;

	status = runCommand(appname, tokens);

	return (status);
}

/**
* main - entry for the application
* @argc: number of arguments
* @argv: lists of arguments
* Return: 0 success 1 failor.
*/
int main(int argc __attribute__((unused)), char *argv[])
{
	char *buffer = malloc(1024);
	size_t count = 0, size = 1024;
	char **tokens = NULL;

	alias = malloc(sizeof(char *));
	init_app();
	if (argc == 2)
		read_command_file(argv[1], argv[0]);
	else
	{
		while ((count = _getline(buffer, size, stdin)))
		{
			if (strlen(buffer) > 0)
			{
				tokens = parse_string(buffer, ' ');
				if (tokens != NULL)
				{
					handleCommand(argv[0], tokens);
					free_memory(tokens);
				}
			}
		}
	}
	free(buffer);
	if (temp_environ != NULL)
		free_memory(temp_environ);

	free(alias);
	return (0);
}
