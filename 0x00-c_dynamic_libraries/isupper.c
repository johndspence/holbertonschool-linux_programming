#include "holberton.h"

/**
 * _isupper - Checks if char is uppercase.\
 *
 * @c: Char to be evaluated.
 *
 * Return: 1 if uppercase, 0 if not.
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}
