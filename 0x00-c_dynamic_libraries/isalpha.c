#include "holberton.h"

/**
 * _isalpha - Checks if char is alphabetic character.
 *
 * @c: Char to be evaluated.
 *
 * Return: 1 if alpha, 0 if not.
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}
