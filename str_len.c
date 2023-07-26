#include "header.h"

/**
 * _strlen - returns the length of a string
 * @s: points to string
 * Return: return c (success)
 */
int _strlen(char *s)
{
	int c = 0;

	while (*(s + c) != '\0')
		c++;
	return (c);
}


