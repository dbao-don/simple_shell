#include "header.h"

/**
 * *_strcpy - function that copies the string pointed including null byte
 * @dest: first pointer
 * @src: second pointer
 * Return: dest value (success)
 */
char *_strcpy(char *dest, char *src)
{
	int to_be_cpy = 0;

	while (src[to_be_cpy] != '\0')
	{
		dest[to_be_cpy] = src[to_be_cpy];
		to_be_cpy++;
	}
	dest[to_be_cpy] = '\0';
	return (dest);
}
