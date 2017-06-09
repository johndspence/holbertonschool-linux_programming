#include "holberton.h"

/**
 * _strlen - Determines the length of a string.
 *
 * @s: String to be measured.
 *
 * Return: Length (int).
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
