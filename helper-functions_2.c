#include "header.h"

/**
* to_int - Converts a string to an integer
* @str: The input string to be converted
* Return: The converted integer
*/
int to_int(char *str)
{
	int i = 1;
	unsigned int j = 0;

	do {
		if (*str == '-')
			i *= -1;
		else if (*str >= '0' && *str <= '9')
			j = (j * 10) + (*str - '0');
		else if (j > 0)
			break;
	} while (*str++);

	return (i * j);
}

/**
* str_compare - Compares two strings
* @str1: The first string
* @str2: The second string
* Return: 1 if the first four characters of the strings match, otherwise 0
*/
int str_compare(char *str1, char *str2)
{
	int i = 0;
	int j = 0;

	while (*(str1 + i) != '\0' && *(str2 + i) != '\0')
	{
		if (*(str1 + i) == *(str2 + i))
			j++;
		if (j == 4)
			return (1);
		i++;
	}

	return (0);
}
