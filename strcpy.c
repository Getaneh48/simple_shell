#include "main.h"

/**
* _strcpy - copys a string from source to destination.
* @dest: destination.
* @src: source.
* @sindex: starting index.
* @eindex: ending index.
*/
void _strcpy(char *dest, char *src, int sindex, int eindex)
{
	int i, j;

	i = 0, j = 0;
	for (i = sindex; i <= eindex; i++)
	{
		dest[j] = src[i];
		j++;
	}
	dest[j] = '\0';
}
