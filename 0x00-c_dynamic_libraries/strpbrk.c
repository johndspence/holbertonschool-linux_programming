#include "holberton.h"

/**
 * _strpbrk - Finds the first character in s that matches any character in
 * accept.
 *
 * @s: The string to be scanned.
 * @accept: String containing the characters to match.
 *
 * Return: Pointer to character in s that matches one of the characters in
 * accept or NULL if no such characters are found.
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (accept[j] == s[i])
			{
				return (&s[i]);
			}
		}
	}
	return ('\0');
}
