#include "main.h"

/**
* _getline - get input from stdinput one line at a time.
* @buffer: memory to store input.
* @size: number of bytes to read.
* @stream: stream.
* Return: number of bytes read
*/
size_t _getline(char *buffer, size_t size, FILE *stream)
{
	size_t count = 0;
	char c;

	if (isatty(STDIN_FILENO))
		show_current_path();

	while ((c = (char)getc(stream)) != '\n' && count < size - 1)
	{
		if ((int)c == EOF)
			return (0);
		buffer[count] = c;
		count++;
	}

	buffer[count] = '\0';
	if (c == '\n')
		count += 1;

	return (count);
}
