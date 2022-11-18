#include "main.h"

/**
* strtoint - converts string to integer.
* @num: string number.
* Return: integer value.
*/
int strtoint(char *num)
{
	size_t i = 0, len = 0;
	int number = 0;

	len = _strlen(num);
	if (num[0] == '-')
		i += 1;

	while (num[i] != '\0')
	{
		len -= 1;
		number += (((int)num[i] - 48) * _pow(10, len));
		i++;
	}

	if (num[0] == '-')
		number = -1 * number;

	return (number);
}
