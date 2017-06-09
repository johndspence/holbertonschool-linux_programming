#include "holberton.h"

/**
 * _strcpy - Copies a string from src to dest.
 * @dest: Destination for copied string.
 * @src: String to copy.
 *
 * Return: Pointer to destination string.
 */
char *_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest);
}
