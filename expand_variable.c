#include "main.h"

/**
* expand_variable - repalce any variable found in a string with its value.
* @str: string
* Return: the exapanded string.
*/
char *expand_variable(char *str)
{
	char **env_list = NULL, **env_name_tokens = NULL, *env_name;
	int i = 0;

	env_list = getenv_list();
	if (env_list != NULL)
	{
		while (env_list[i] != NULL)
		{
			env_name_tokens = tokenize(env_list[i], '=');
			env_name = malloc(2 + strlen(env_name_tokens[0]));
			strcpy(env_name, "$");
			strcat(env_name, env_name_tokens[0]);
			str = perform_variable_replacement(str, env_name, env_name_tokens[1]);
			free(env_name);
			free_memory(env_name_tokens);
			i++;
		}
	}
	return (str);
}

/**
* perform_variable_replacement - handles the replacement process.
* @str: source string.
* @env_name: enviroment variable name.
* @env_val: enviroment variable's value.
* Return: the replacement string.
*/
char *perform_variable_replacement(char *str, char *env_name, char *env_val)
{
	int match_start = 0, k = 0, j = 0, sindex __attribute__((unused));
	char *temp = NULL;

	for (k = 0; str[k] != '\0'; k++)
	{
		if (str[k] == env_name[j])
		{
			sindex = k;
			if (env_name[j + 1] == '\0')
			{
				match_start = k - strlen(env_name);
				temp = replace_variable(str, env_val, match_start, k + 1);
				if (temp != NULL)
				{
					free(str);
					str = temp;
					k = strlen(env_val + k);
				}
				break;
			}
			j++;
		}
		else
		{
			j = 0;
			sindex = 0;
		}
	}
	return (str);
}

/**
* replace_variable - substituet a variable with its value.
* @src_str: source string.
* @r_str: replacement string.
* @sind: starting index.
* @i: ending index.
* Return: the replaced string.
*/
char *replace_variable(char *src_str, char *r_str, int sind, int i)
{
	char *str1 = NULL, *str2 = NULL, *new_str = NULL;

	str1 = malloc(sind + 1);
	if (str1 == NULL)
	{
		dprintf(2, "unable to allocate memory\n");
		return (NULL);
	}

	str2 = malloc((strlen(src_str) - i) + 1);
	if (str2 == NULL)
	{
		dprintf(2, "unable to allocate memory\n");
		return (NULL);
	}

	new_str = malloc(sind + (strlen(src_str) - i) + strlen(r_str) + 4);
	if (new_str == NULL)
	{
		dprintf(2, "unable to allocate memory\n");
		return (NULL);
	}

	_strcpy(str1, src_str, 0, sind);
	_strcpy(str2, src_str, i, strlen(src_str));
	_strcpy(new_str, str1, 0, strlen(str1));
	_strcat(new_str, r_str);
	_strcat(new_str, str2);
	free(str1);
	free(str2);

	return (new_str);
}
