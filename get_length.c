#include "main.h"

/**
* get_length - return the length of an array.
* @str: array
* Return: length
*/
int get_length(char **str)
{
	int i = 0;

	while (str[i] != NULL)
		i++;

	return (i);
}
