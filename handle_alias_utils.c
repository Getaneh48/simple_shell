#include "main.h"

/**
* handle_alias_process - handles creating and updating of aliases
* @tokens: array args
*/
void handle_alias_process(char **tokens)
{
	int arg_length, result, i = 1;
	char **args = NULL, *token, *tk;

	i = 1;
	while (tokens[i] != NULL)
	{
		token = tokens[i];
		if (is_setting_alias(token))
		{
			tk = remove_quote(token);
			args = parse_string(tk, '=');
			free(tk);
			if (args != NULL)
			{
				arg_length = get_length(args);
				if (arg_length != 2)
					dprintf(2, "%s: '%s': not found\n", tokens[0], args[0]);
				else
				{
					result = check_alias_exists(args[0]);
					if (result != -1)
						update_alias(args);
					else
						result = add_new_alias(args);
				}
				free_memory(args);
			}
			else
				printf("unable to parse args\n");
		}
		else
			show_alias_by_name(token);

		i++;
	}
}

/**
* is_setting_alias - check if the command is for creating an alias.
* @al: alias command.
* Return: 1 true 0 false.
*/
int is_setting_alias(char *al)
{
	int i = 0;
	int result = FALSE;

	while (al[i] != '\0')
	{
		if (al[i] == '=')
		{
			result = TRUE;
			break;
		}
		i++;
	}
	return (result);
}

/**
* remove_quote - removes quote from a string.
* @token: string token.
* Return: quote removed string.
*/
char *remove_quote(char *token)
{
	char *str, len = 0;

	if (token != NULL)
	{
		len = strlen(token);
		if (token[0] == '"' && token[len - 1] == '"')
		{
			str = malloc(len);
			_strcpy(str, token, 1, len - 2);
			return (str);
		}
		else
		{
			str = strdup(token);
			return (str);
		}
	}
	return (NULL);
}

/**
* create_alias_string - creates the alias string in the format name='value'.
* @alias_cmd: the alias values.
* Return: the alias string.
*/
char *create_alias_string(char **alias_cmd)
{
	char *new_str = NULL;

	new_str = malloc(strlen(alias_cmd[0]) + strlen(alias_cmd[1]) + 4);
	if (new_str != NULL)
	{
		strcpy(new_str, alias_cmd[0]);
		strcat(new_str, "=");
		strcat(new_str, "'");
		strcat(new_str, alias_cmd[1]);
		strcat(new_str, "'");
	}

	return (new_str);
}

/**
*check_alias_exists - check if an alias exists.
* @name: name of the alias.
* Return: -1 not found >= 0 index of the alias
*/
int check_alias_exists(char *name)
{
	int alias_len = 0, i = 0, al_index = -1;
	char **al_name = NULL;

	alias_len = get_length(alias);
	if (alias_len <= 0)
		return (-1);

	while (alias[i] != NULL)
	{
		al_name = tokenize(alias[i], '=');
		if (al_name != NULL)
		{
			if (strcmp(al_name[0], name) == 0)
			{
				al_index = i;
				break;
			}
			free_memory(al_name);
		}
		i++;
	}

	return (al_index);
}
