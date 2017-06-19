#include "hls_hdr.h"

/**
 * chkdir - checks directory and prints contents.
 * @path: Directory path
 *
 * Return: 0
 */
int chkdir(char *path)
{
	DIR *dir;
	struct dirent *read;

	dir = opendir(path);
	if (errno == ENOENT)
	{
		printf("hls: cannot access %s: No such file or directory\n", path);
		return (2);
	}
	else
	{
		while ((read = readdir(dir)) != NULL)
		{
			if (read->d_name[0] != '.')
			{
				printf("%s\n", read->d_name);
			}
		}
		closedir(dir);
	}
	return (0);
}
