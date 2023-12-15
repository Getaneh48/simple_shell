#include "main.h"

/**
* substr - returns a sub string.
* @src: srouce string.
* @dest: destination string.
* @sp: start position.
* @ep: end position.
* Return: number of bytes of a sub string.
*/
int substr(char *src, char *dest, size_t sp, size_t ep)
{
	size_t s = sp, i = 0;

	if (ep == 0)
		ep = strlen(src);

	if (ep <= sp)
		return (-1);

	while (s < ep)
	{
		dest[i] = src[s];
		s++;
		i++;
	}
	dest[i] = '\0';

	return (s - sp);
}
