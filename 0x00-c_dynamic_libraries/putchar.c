#include "holberton.h"
#include <unistd.h>

/**
 * _putchar - prints a char.
 *
 * @c: Char to be printed.
 *
 * Return: 0.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
