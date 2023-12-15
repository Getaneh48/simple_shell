#include "main.h"
#include <stdio.h>

/**
* _strtoken- split a string to multiple array of words
* @string: string to be splited based on a specific delimeter
* Return: array of splitted words
*/
char **_strtoken(char *string)
{
	char **tokens = NULL;
	int count = word_count(string);
	int i = 0, j = 0, index = 0, quote = 0, open_quote_index = 0;
	int end_quote_index = 0;

	tokens = malloc(sizeof(char *) * (count + 3));
	if (tokens == NULL)
		return (NULL);
	while (string[i] != '\0')
	{
		if (string[i] == '\"')
		{
			quote += 1;
			if (quote == 1)
				open_quote_index = i;
			if (quote == 2)
			{
				end_quote_index = i;
				tokens[j] = copy_str(string, open_quote_index, end_quote_index + 1);
				j++;
				/*reset everything*/
				quote = 0;
				open_quote_index = end_quote_index = 0;
				index = i + 1;
			}
		}
		else if (string[i] == ' ' && quote == 0)
		{
			if (string[i + 1] != ' ' && i > index)
			{
				tokens[j] = copy_str(string, index, i);
				index = i + 1;
				j++;
			}
		}
		i++;
	}
	tokens[j] = copy_str(string, index, i);
	tokens[j + 1] = NULL;
	return (tokens);
}
