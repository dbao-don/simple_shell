#include "header.h"
/**
 * str_tokens - Splits a string into tokens using space
 * and newline as delimiters.
 * @str: Input string to be split into tokens.
 *
 * Return: Array of strings containing the tokens, or NULL on failure.
 */
char **str_tokens(char *str)
{
	char **result;
	char *token;
	/*
	 * malloc token pointer array with the same length
	 * as 'str' to ensure an overflow doesn't happen:
	 */
	int str_len;
	int result_index = 0;

	if (!str)
		return (NULL);

	str_len = _strlen(str);

	result = malloc(sizeof(char *) * (str_len + 1));
	if (!result)
		return (NULL);

	token = strtok(str, " \n");
	while (token)
	{
		result[result_index] = token;
		result_index++;
		token = strtok(NULL, " \n");
	}
	result[result_index] = NULL;

	return (result);
}

