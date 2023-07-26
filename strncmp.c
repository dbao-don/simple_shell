#include "header.h"

/**
* _strncmp - compares n bytes of two strings
* @s1: character string
* @s2: character string
* @n: number of byte
* Return: zero if string are the same
*/
int _strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	do {
		if (*s1 != *s2++)
			return (*(unsigned char *)s1 - *(unsigned char *) --s2);
		if (*s1++ == 0)
			break;
	} while (--n != 0);

	return (0);
}
