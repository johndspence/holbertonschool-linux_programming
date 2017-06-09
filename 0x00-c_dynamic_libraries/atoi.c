#include "holberton.h"

/**
 * _atoi - Converts a s of numbers to an integer.
 * @s: s to be converted
 *
 * Return: Integer from converted s.
 */
int _atoi(char *s)
{
	int i;
	int val;
	int sign;

	sign = 1;
	val = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-' && !val)
		{
			sign = sign * -1;
		}
		else if (s[i] == '+' && !val)
		{
			sign = sign * 1;
		}
		else if (s[i] > '9' || s[i] < '0')
		{
			return (0);
		}
		else
		{
			val = (val * 10) + (s[i] - '0');
		}
	}
	return (val * sign);
}
