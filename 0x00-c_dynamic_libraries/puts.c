#include "holberton.h"

/**
 * _puts - Prints a string char to stdout, followed by newline.
 *
 * @s: String to print.
 *
 * Return: (void)
 */
void _puts(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	_putchar('\n');
}
