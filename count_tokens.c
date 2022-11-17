#include "main.h"

/**
* count_tokens - counts the total number of array pointer.
*
* @tokens: array pointer.
*
* Return: count of the array.
*/
int count_tokens(char **tokens)
{
	size_t i = 1;

	if (tokens != NULL)
	{
		while (tokens[i] != NULL)
		{
			i++;
		}
	}
	else
		i = -1;

	return (i);
}
