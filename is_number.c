#include "main.h"
/**
* is_number - check if the input is an integer or not.
* @num: value to be checked.
* Return: 0 success 1 failor.
*/
int is_number(char *num)
{
	size_t i = 0, n, isnum = 0;

	while (num[i] != '\0')
	{
		n = (int) num[i];
		if (n < 48 || n > 57)
		{
			isnum = 1;
			break;
		}
		i++;
	}

	return (isnum);
}
