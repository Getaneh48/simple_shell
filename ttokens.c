#include "main.h"

/**
* total_tokens - return the number of tokens.
* @str: source string.
* @delim: delimeter.
* Return: total count.
*/
size_t total_tokens(char *str, char delim)
{
	size_t total = 0;
	int i = 0;

	while (str[i])
	{
		if (str[i] == delim)
			total += 1;
		i++;
	}

	total += 1;
	return (total);
}
