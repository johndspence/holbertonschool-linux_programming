#include "holberton.h"

/**
 * _strstr - locates a substring
 *
 * @haystack: string to search in
 * @needle: stringt to search for;
 *
 * Return: pointer to the beginning of the located subtring, NULL
 * if not found
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *start = haystack;
		char *substr = needle;

		while (*haystack && *substr && *haystack == *substr)
		{
			haystack++;
			substr++;
		}
		if (!*substr)
			return (start);
		haystack = start + 1;
	}
	return ('\0');
}
