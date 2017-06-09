#include "holberton.h"

/**
 * _strcmp - Compares ther value of two strings..
 *
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: 1 if a > b or a < b, 0 if equal (int).
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] != '\0')
	{
		i++;
	}
	if (s1[i] > s2[i])
	{
		return (1);
	}
	else if (s1[i] < s2[i])
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
