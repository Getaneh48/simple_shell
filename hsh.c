#include "main.h"
#include "global_var.h"

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
* @tokens: array of strings.
* Return: 0 for success 1 failer.
*/
int runCommand(char **tokens)
{
	int builtin = 0, status __attribute__((unused));
	char *cmdpath = NULL;

	if (tokens != NULL)
	{
		builtin = checkBuiltinCmd(tokens[0]);
		if (builtin != -1)
		{
			builtin_func[builtin](tokens);
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
				printf("%s: command not found\n", tokens[0]);

			return (1);
		}
	}

	return (1);
}

/**
* handleCommand - runs a command
* @tokens: array of strings.
* Return: status of a command.
*/
int handleCommand(char **tokens)
{
	size_t status = 0;

	status = runCommand(tokens);

	return (status);
}

/**
* main - entry for the application
* Return: 0 success 1 failor.
*/
int main(void)
{
	char *buffer = malloc(1024);
	size_t count = 0, size = 1024;
	char **tokens = NULL;

	alias = malloc(sizeof(char *));
	init_app();
	show_current_path();
	while ((count = _getline(buffer, size, stdin)))
	{
		if (strlen(buffer) > 0)
		{
			tokens = parse_string(buffer, ' ');
			if (tokens != NULL)
			{
				handleCommand(tokens);
				free_memory(tokens);
			}
		}
		show_current_path();
	}
	free(buffer);
	if (temp_environ != NULL)
		free_memory(temp_environ);

	free(alias);
	return (0);
}
