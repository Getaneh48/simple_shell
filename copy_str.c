#include <stdlib.h>
/**
* copy_str- copies a specific string between the given start and end index
* from the source to a new memory location
* @source: a source string the string is being copied from
* @st_index: the start of the index the copieng should begen
* @end_index: the end index the copieng should stop to
* Return: the new copied string
*/
char *copy_str(char *source, unsigned int st_index, unsigned int end_index)
{
	char *str = malloc(sizeof(char *) * (end_index - st_index));

	unsigned int i;
	int j = 0;

	if (str == NULL)
		return (NULL);
	for (i = st_index; i < end_index; i++)
	{
		str[j] = source[i];
		j++;
	}
	str[j] = '\0';
	return (str);
}
