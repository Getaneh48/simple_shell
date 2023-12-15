#include "main.h"

/**
* _strlen - returns the length of a string
*
* @s: the string to be checked.
*
* Return: the length of the string.
*
*/

int _strlen(char *s)
{
	int len;

	len = 0;

	len = _strlen_rec(s, len);

	return (len);
}

/**
* _strlen_rec - finds the length of the string
*
* @c: the string whose length to be checked.
* @len: length of the string
*
* Return: the string length as integer.
*
*/

int _strlen_rec(char *c, int len)
{
	int d;

	d = 0;

	if (*c == '\0')
		return (len);

	d = len + 1;
	len = _strlen_rec(++c, d);

	return (len);
}
