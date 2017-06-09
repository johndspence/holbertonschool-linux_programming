#include "holberton.h"

/**
 * _strchr - Finds first occurence of a char in a string.
 *
 * @s: String to be searched.
 * @c: Char to be located in string.
 *
 * Return: Pointer to memory location holding char.
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
		{
			break;
		}
		s++;
	}
	return (s);
}
