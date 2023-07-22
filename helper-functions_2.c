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

/**
* construct_path - Concatenates a directory and command to form a full path
* @command: The command to be executed
* @env: The directory to be concatenated
* Return: The constructed full path
*/
char *construct_path(char *command, char *env)
{
	char *full_path;

	if (command[0] == '/')
		return (command);

	full_path = str_concat(env, command);

	return (full_path);
}

/**
* str_concat - Concatenates two strings and returns the result
* @dest: The destination string
* @src: The source string to be concatenated
* Return: The concatenated string
*/
char *str_concat(char *dest, char *src)
{
	int i, j;
	int len_dest = str_length(dest);
	int len_src = str_length(src);
	char *concat;

	concat = malloc(sizeof(char) * (len_dest + len_src + 1));

	for (i = 0; i < len_dest; i++)
		concat[i] = dest[i];
	concat[i++] = '/';
	for (j = 0; j < len_src; j++, i++)
		concat[i] = src[j];
	concat[i] = '\0';

	return (concat);
}

/**
* str_length - Calculates the length of a string
* @s: The input string
* Return: The length of the string
*/
int str_length(char *s)
{
	int c = 0;

	while (*(s + c) != '\0')
		c++;
	return (c);
}
