#include "holberton.h"

/**
 * _abs - Computes absolute value of an integer.
 * @n: Integer to be evaluated.
 *
 * Return: Absolute value of the integer.
 */
int _abs(int n)
{
	if (n < 0)
	{
		n = n * -1;
	}
	return (n);
}
