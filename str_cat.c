#include "header.h"

/**
 * _strcat - function that concatenates two strings
 * @dest: first array
 * @src: second array
 * Return: pointer to dest (success)
 */
char *_strcat(char *dest, char *src)
{
	int len, i;

	len = 0;
	i = 0;

	while (dest[len] != '\0')
		len++;

	while (src[i] != '\0')
	{
		dest[len] = src[i];
		len++;
		i++;
	}

	dest[len] = '\0';

	return (dest);
}
