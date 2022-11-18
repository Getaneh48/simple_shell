#include "main.h"

/**
* _strcmp - compares two strings
*
* @s1: first string argument
* @s2: second string argument
*
* Return: <0 if s1 < s2 >0 if s1 > s2 and 0 if they are equal.
*
*/
int _strcmp(char *s1, char *s2)
{
	int c1, c2, result;

	result = 0;
	while (*s1 != '\0')
	{

		c1 = (int) *s1;
		c2 = (int) *s2;

		if ((c1 - c2) != 0)
		{
			result = c1 - c2;
			break;
		}
		s1 = s1 + 1;
		s2 = s2 + 1;
	}

	c1 = (int) *s1;
	c2 = (int) *s2;

	result = c1 - c2;

	return (result);
}
