#include "main.h"

/**
* handle_alias - handles creating and updating of aliases
* @tokens: array args
* Return: 0 success -1 failor
*/
int handle_alias(char **tokens)
{
	int token_length;

	if (tokens[0] != NULL)
	{
		token_length = get_length(tokens);
		if (token_length == 1)
		{
			list_alias();
			return (0);
		}
		else
		{
			handle_alias_process(tokens);
		}
	}

	return (0);
}

/**
* show_alias_by_name - get alias by name.
* @name: name of the alias.
*/
void show_alias_by_name(char *name)
{
	int i = 0;
	char **al_tokens = NULL;

	while (alias[i] != NULL)
	{
		al_tokens = tokenize(alias[i], '=');
		if (strcmp(al_tokens[0], name) == 0)
		{
			printf("alias %s\n", alias[i]);
			break;
		}
		i++;
	}
	free_memory(al_tokens);
}

/**
* list_alias - show the lists of alias.
*/
void list_alias(void)
{
	int k = 0;

	while (alias[k] != NULL)
	{
		printf("alias %s\n", alias[k]);
		k++;
	}
}

/**
* update_alias - updates the value of an alias.
* @new_al: list of the new alias tokens.
* Return: 1 success 0 failor.
*/
int update_alias(char **new_al)
{
	int success = FALSE;
	char **al_str = NULL, *str;
	int i = 0;

	while (alias[i] != NULL)
	{
		al_str = tokenize(alias[i], '=');
		if (strcmp(new_al[0], al_str[0]) == 0)
		{
			str = create_alias_string(new_al);
			alias[i] = str;
			success = TRUE;
			break;
		}
		i++;
	}
	free_memory(al_str);

	return (success);
}

/**
* add_new_alias - adds a new a alias to the alias list.
* @al: list of the alias values.
* Return: 1 success 0 failor.
*/
int add_new_alias(char **al)
{
	int success = FALSE, alias_len = 0;
	char *new_al = NULL;

	alias_len = get_length(alias);
	alias = (char **)realloc(alias, (alias_len + 1) * sizeof(char *));
	if (alias != NULL)
	{
		new_al = create_alias_string(al);
		if (new_al != NULL)
		{
			alias[alias_len] = new_al;
			alias[alias_len + 1] = NULL;
			success = TRUE;
		}
		else
		{
			alias = realloc(alias, alias_len * sizeof(char *));
		}
	}

	return (success);
}
