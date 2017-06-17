#include "hls_hdr.h"

/**
 * main - Main program.
 * @argc: Argument count.
 * @argv: Array of argument strings.
 *
 *
 *
 * Return: Exit value success or failure.
 */

int main(int argc, char **argv)
{
	char *path;
	char *parameter;

	path = NULL;
	parameter = "No Parameter";
	printf("argc = %d\n", argc);
	if (argc == 1)
	{
		path = "./";
		parameter = NULL;
	}
	if (argc == 2)
	{
		if (argv[1][0] == '-')
		{
			path = "./";
			parameter = argv[1];
		}
		else
		{
			path = argv[1];
			parameter = NULL;
		}
	}
	if (argc == 3)
	{
		if (argv[1][0] == '-')
		{
			path = argv[2];
			parameter = argv[1];
		}
		else
		{
			path = argv[1];
			parameter = argv[2];
		}
	}
	if (argc > 3)
	{
		/* Put correct error message and exit value here */
		printf("too many arguments\n");
		return(1);
	}

	if (path)
	{
		printf("path: %s\n", path);
		if (chk_dir(path) == 2)
		{
			return (2);
		}
	}
	if (parameter)
	{
		printf("parameter: %s\n", parameter);
	}
	return(0);
}
