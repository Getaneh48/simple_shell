#include "main.h"
/**
* free_memory - frees the allocated memory in heap.
* @mem: array of memory.
*/
void free_memory(char **mem)
{
	int i = 0;

	while (mem[i] != NULL)
	{
		free(mem[i]);
		i++;
	}
	free(mem);
}
