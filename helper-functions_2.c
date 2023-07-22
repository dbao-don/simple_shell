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
