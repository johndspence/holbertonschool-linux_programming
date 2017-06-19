#include "hls_hdr.h"

/**
 * main - Main program.
 * @argc: Argument count.
 * @argv: Array of argument strings.
 *
 * Return: Exit value success or failure.
 */
int main(int argc, char **argv)
{
	char *path;

	path = NULL;
	if (argc == 1)
		path = "./";
	if (argc == 2)
	{
		if (argv[1][0] == '-')
			path = "./";
		else
			path = argv[1];
	}
	if (argc == 3)
	{
		if (argv[1][0] == '-')
			path = argv[2];
		else
			path = argv[1];
	}
	if (argc > 3)
	{
		printf("too many arguments\n");
		return (1);
	}

	if (path)
	{
		if (chkdir(path) == 2)
			return (2);
	}
	return (0);
}
