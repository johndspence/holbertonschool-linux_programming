#include "holberton.h"

/**
 * _memset - fills memory with a constant byte
 * @s: Memory location to initialize.
 * @b: Constant byte.
 * @n: Number of bytes to initialize.
 *
 * Return: Memory filled array.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
