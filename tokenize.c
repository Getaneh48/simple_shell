#include "main.h"

/**
* tokenize - break down a string with a delimeter.
* @str: string to be tokenized.
* @delim: delimeter used to break the string.
* Return: address of the lists of tokens.
*/
char **tokenize(char *str, char delim)
{
	int totalt = total_tokens(str, delim);
	char **tokens = (char **) malloc((totalt + 2) * sizeof(char *));
	int sp = 0, ep = 0, i = 0, j = 0;
	char *token = NULL;

	while (str[i] != '\0')
	{
		if (delim == ' ')
		{
			if (str[i] == ' ' || str[i] == '\t')
			{
				ep = i - 1;
				token = malloc((ep - sp) + 2);
				_strcpy(token, str, sp, ep);
				tokens[j] = token;
				sp = i + 1;
				j += 1;
			}
		}
		else
		{
			if (str[i] == delim)
			{
				ep = i - 1;
				token = malloc((ep - sp) + 2);
				_strcpy(token, str, sp, ep);
				tokens[j] = token;
				sp = i + 1;
				j += 1;
			}
		}
		i++;
	}
	ep = i - 1;
	token = malloc((ep - sp) + 2);
	_strcpy(token, str, sp, ep);
	tokens[j] = token;
	tokens[j + 1] = NULL;

	return (tokens);
}
