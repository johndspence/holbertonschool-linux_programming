#include "holberton.h"

/**
 * _strncat - Concatenates two strings up to n bytes.
 *
 * @dest: Destination string.
 * @src: Source string.
 * @n: Number of bytes to concatenate.
 *
 * Return: Concatenated string (char *).
 */
char *_strncat(char *dest, char *src, int n)
{
	while (*dest)
	{
		dest++;
	}
	while (n != 0)
	{
		*dest = *src;
		dest++;
		src++;
		n = n - 1;
	}
	*dest = '\0';
	return (dest);
}
