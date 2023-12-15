#include "main.h"

/**
* show_current_path - construct a path of the current directory
* to be displayed on the command prompt.
*/
void show_current_path(void)
{
	char *home __attribute__((unused)), *cwd = NULL,
	     *new_path __attribute__((unused));
	char *user, *str __attribute__((unused));
	int i = 0, match = TRUE, home_len = 0, cwd_len = 0;

	home = _getenv("HOME");
	cwd = _getenv("PWD");
	user = _getenv("USER");
	if (home != NULL && cwd != NULL)
	{
		home_len = strlen(home);
		cwd_len = strlen(cwd);
		if (cwd_len >= home_len)
		{
			while (home[i] != '\0')
			{
				if (home[i] != cwd[i])
				{
					printf("%s@%s$ ", user, cwd);
					match = FALSE;
					break;
				}
				i++;
			}
			if (match)
			{
				replace_homepath(home, cwd, home_len, cwd_len, i, "~");
			}
		}
		else
		{
			printf("%s@%s$ ", user, cwd);
		}
		free(home);
		free(cwd);
		free(user);
	}

}

/**
* replace_homepath - replace the home path a user to a symbol ~.
* @home: home path of a user.
* @cwd: current working dir of a user.
* @home_len: length of the home path.
* @cwd_len: length of the current working dir path.
* @i: index.
* @symbol: symbold to replace with.
*
* Return: 0 success 1 failor.
*/
void replace_homepath(char *home __attribute__((unused)), char *cwd,
int home_len, int cwd_len, int i, char *symbol)
{
	char *new_path = NULL, *str = NULL, *user = NULL;

	user = _getenv("USER");
	if (cwd_len == home_len)
	{
		new_path = malloc(2);
		strcpy(new_path, symbol);
		printf("%s@%s$ ", user, new_path);
	}
	else
	{
		new_path = malloc((cwd_len - i) + 3);
		str = malloc((cwd_len - i) + 3);

		if (new_path != NULL && str != NULL)
		{
			strcpy(new_path, symbol);
			substr(cwd, str, i, 0);
			strcat(new_path, str);
			printf("%s@%s$ ", user, new_path);
		}
	}

	free(new_path);
	if (str != NULL)
		free(str);
	if (user != NULL)
		free(user);
}
