#include "holberton.h"

/**
 * _strncpy - Copies a string from src to dest.
 * @dest: Destination for copied string.
 * @src: String to copy.
 * @n: Number of characters to copy.
 *
 * Return: Pointer to destination string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	while (*src && n > 0)
	{
		*dest = *src;
		src++;
		dest++;
		n--;
	}
	*dest = '\0';
	return (dest);
}
