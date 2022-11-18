#include "main.h"

int get_length(char **str)
{
	int i = 0;
	
	while (str[i] != NULL)
		i++;

	return (i);
}
