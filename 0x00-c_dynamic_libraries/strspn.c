#include "holberton.h"

/**
 * _strspn - calculates the length (in bytes) of the initial segment of s which
 * consists entirely of bytes in accept.
 *
 *@s: initisl segment.
 *@accept: Prefix substring.
 *
 * Return: Number of bytes in the initial segment of s which consist only of
 * bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i;
	unsigned int j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
			{
				break;
			}
		}
		if (!accept[j])
		{
			break;
		}
	}
	return (i);
}
