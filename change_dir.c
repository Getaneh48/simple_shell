#include "main.h"

/**
* change_dir - change the current directory.
*
* @path: path of the dir.
*
* Return: -1 for error 0 for success.
*/
int change_dir(char *path)
{
	char str[100], cwd[100], oldpwd[100], *args[4];
	int result;

	if (path)
	{
		getcwd(oldpwd, 100); /* before changing working dir back up it first */
		if (strcmp(path, "-") == 0)
		{
			if (handle_cd_hyphen() == -1)
				return (-1);
		}
		else if (strcmp(path, "~") == 0 || strcmp(path, "cd") == 0)
		{
			if (handle_cd_tilder() == -1)
			{
				return (-1);
			}
		}
		else if (path[0] == '$')
		{
			result = handle_dollar_symbol(path, str);
			if (result == -1)
				return (-1);
		}
		else
		{
			if (chdir(path) == -1)
				return (-1);
		}
	}
	else
		return (-1);
	/* update the enviroment virable 'PWD' */
	args[0] = "cd";
	args[1] = "PWD";
	args[2] = getcwd(cwd, 100);
	args[3] = NULL;
	replace_env(args);
	update_oldpwd(oldpwd);
	return (0);
}

/**
* handle_dollar_symbol - changes the directory
* to the value of the enviroment variable value.
*
* @path: path str.
* @str: string.
*
* Return: 0 success -1 on error.
*/
int handle_dollar_symbol(char *path, char *str)
{
	char *env_path = NULL;
	int cd_result, result = 0;

	result = substr(path, str, 1, strlen(path));
	if (result)
	{
		env_path = _getenv(str);
		if (env_path != NULL)
		{
			cd_result = chdir(env_path);
			free(env_path);
			if (cd_result == -1)
				return (-1);
		}
		else
			return (-1);

	}
	else
		return (-1);

	return (0);
}

/**
* handle_cd_tilder - handles the ~ symbol when
* changing the directory..
*
* Return: -1 for error 0 for success.
*/
int handle_cd_tilder(void)
{
	char *home_path = _getenv("HOME");

	if (home_path != NULL)
	{
		if (chdir(home_path) == -1)
		{
			free(home_path);
			return (-1);
		}
		free(home_path);
	}
	else
		return (-1);

	return (0);
}

/**
* handle_cd_hyphen - handles the - symbol when
* changing the directory..
*
* Return: -1 for error 0 for success.
*/
int handle_cd_hyphen(void)
{
	char *oldpwd = NULL;

	oldpwd = _getenv("OLDPWD");
	if (oldpwd != NULL)
	{
		if (chdir(oldpwd) == -1)
		{
			free(oldpwd);
			return (-1);
		}

		free(oldpwd);
	}
	else
		return (-1);

	return (0);
}

/**
* update_oldpwd - update the OLDPWD enviroment variable.
*
* @path: path to directory
*/
void update_oldpwd(char *path)
{
	char *args[4];

	args[0] = "";
	args[1] = "OLDPWD";
	args[2] = path;
	args[3] = NULL;
	replace_env(args);
}
