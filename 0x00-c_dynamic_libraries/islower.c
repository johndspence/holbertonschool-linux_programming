#include "holberton.h"

/**
 * _islower - Checks if char is lowercase.\
 *
 * @c: Char to be evaluated.
 *
 * Return: 1 if lowercase, 0 if not.
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}
