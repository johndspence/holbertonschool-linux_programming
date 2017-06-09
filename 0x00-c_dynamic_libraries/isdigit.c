#include "holberton.h"

/**
 * _isdigit - Checks if char is numeric.\
 *
 * @c: Char to be evaluated.
 *
 * Return: 1 if digit, 0 if not.
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
