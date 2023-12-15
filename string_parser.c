#include "main.h"

/**
* parse_string - handles quotations and enviroment variable
* expansion.
* @str: string to be parsed.
* @delim: delimeter to use.
* Return: addrss of parsed string.
*/
char **parse_string(char *str, char delim)
{
	char **tokens = NULL, *temp_token __attribute__((unused)), *token = NULL;
	int i, sq, eq, in_quote, stoken, etoken, diff __attribute__((unused)), j = 0;

	i = 0, sq = -1, eq = -1, in_quote = FALSE, stoken = 0, etoken = 0, diff = 0;
	temp_token = NULL;
	tokens = malloc(sizeof(char *));
	tokens[0] = NULL;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			in_quote = TRUE;
			if (sq == -1)
			{
				sq = i;
			}
			else
			{
				eq = i;
				in_quote = FALSE;
			}
			continue;
		}

		if (str[i] == delim && in_quote == FALSE)
		{
			token = stripe_quote(str, &stoken, &etoken, &sq, &eq, i);
			token = expand_variable(token);
			tokens = allocate_mem(tokens, token, &j);
		}

	}
	token = stripe_quote(str, &stoken, &etoken, &sq, &eq, i);
	token = expand_variable(token);
	tokens = allocate_mem(tokens, token, &j);
	return (tokens);
}

/**
* allocate_mem - allocates memory.
* @buffer: buffer to store data.
* @str: string
* @j: loop index.
* Return: address of newly allocated memrory.
*/
char **allocate_mem(char **buffer, char *str, int *j)
{
	if (str != NULL)
	{
		if (buffer[*j] == NULL)
		{
			buffer = realloc(buffer, (*j + 1) * sizeof(char *) + sizeof(char *));
			if (buffer != NULL)
			{
				buffer[*j] = str;
				buffer[*j + 1] = NULL;
				*j += 1;
			}
		}
	}

	return (buffer);
}

/**
* stripe_quote - remove quotation.
* @str: source string.
* @stoken: start index.
* @etoken: end index.
* @sq: sindex.
* @eq: eindex
* @i: loop index.
* Return: string.
*/
char *stripe_quote(char *str, int *stoken, int *etoken,
int *sq, int *eq, int i)
{
	char *token = NULL, *temp_token __attribute__((unused));

	int diff = 0;

	temp_token = NULL;
	if (*sq != -1 && *eq != -1)
	{
		diff = *sq - *stoken;
		if (diff > 1)
		{
			token = malloc((*eq - *sq) + diff + 1);
			temp_token = malloc((*eq - *sq) + 1);
			substr(str, token, *stoken, *sq);
			substr(str, temp_token, *sq + 1, *eq);
			_strcat(token, temp_token);
			free(temp_token);
		}
		else
		{
			token = malloc((*eq - *sq) + 1);
			substr(str, token, *sq + 1, *eq);
		}
		*sq = *eq = -1;
		*etoken = i;
		*stoken = i + 1;
	}
	else
	{
		diff = 0;
		*etoken = i;
		token = malloc((*etoken - *stoken) + 1);
		substr(str, token, *stoken, *etoken);
		*stoken = *etoken + 1;
	}

	return (token);
}
