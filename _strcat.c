#include "main.h"

/**
* _strcat - concatenates two strings.
*
* @dest: the source string will be cancatenated to.
* @src: the source string that will be concatenated to dest.
*
* Return: the concatenated string
*
*/

char *_strcat(char *dest, char *src)
{
	char *org_dest = dest;

	dest = dest + _strlen(dest);

	while (*src != '\0')
	{
		*dest = *src;
		src += 1;
		dest += 1;
	}

	*dest = '\0';

	return (org_dest);

}
