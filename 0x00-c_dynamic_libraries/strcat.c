#include "holberton.h"
/**
 * _strcat - Concatenates two strings.
 *
 * @dest: Destination string.
 * @src: Source string.
 *
 * Return: Concatenated string (char *).
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int len;

	len = _strlen(dest);
	for (i = 0; src[i]; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
	return (dest);
}
