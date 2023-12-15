#include "main.h"

/**
* _exitt - function that exits a program.
*
* @appname: the application name
* @tokens: lists of arguments.
*
* Return: 1 for error 0 success.
*
*/
int _exitt(char *appname __attribute__((unused)), char **tokens)
{
	int argc = count_tokens(tokens);

	if (argc == 1)
	{
		exit(0);
	}
	else if (argc == 2)
	{
		if (is_number(tokens[1]) == 0)
		{
			int num = strtoint(tokens[1]);

			exit(num);
		}
		else
		{
			dprintf(2, "%s: %s: numeric argument requires\n", tokens[0], tokens[1]);
			return (1);
		}
	}
	else
	{
		dprintf(2, "%s: too many arguments\n", tokens[0]);
		return (1);
	}
}
