/**
* word_count - counts the number of words in a string.
* @string: string to be counted
* Return: the number of words
*/
int word_count(char *string)
{
	int count = 0;

	while (*string != '\0')
	{
		if (*string == ' ')
			count++;

		string++;
	}

	return (count);
}
