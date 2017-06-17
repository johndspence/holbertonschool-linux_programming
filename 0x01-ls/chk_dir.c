#include "hls_hdr.h"

int chk_dir(char *path)
{
	DIR *dir;
	struct dirent *read;
	int file_count;
	int file_cnt_iter;
	char **file_list;

	file_list = NULL;
	file_count = 0;
	dir = opendir(path);
	if (errno == ENOENT)
	{
		printf("hls: cannot access %s: No such file or directory\n", path);
		return(2);
	}
	else
	{
		while ((read = readdir(dir)) != NULL)
		{
			if (read->d_name[0] != '.')
			{
				printf("file:  %s\n", read->d_name);
				file_count++;
			}
		}
		closedir(dir);
		printf("file count: %d\n", file_count);
		if (!file_count)
		{
			printf("!file_count, returning 0\n");
			return (0);
		}

		read = NULL;
		dir = NULL;
		dir = opendir(path);
		file_cnt_iter = 0;
		file_list = malloc(file_count * sizeof(char *));

		while ((read = readdir(dir)) != NULL)
		{
			if (read->d_name[0] != '.')
			{
				file_list[file_cnt_iter] = malloc(strlen(read->d_name) * sizeof(char));
				strcpy(file_list[file_cnt_iter], read->d_name);
				printf("file_list[%d]: %s\t", file_cnt_iter, file_list[file_cnt_iter]);
				file_cnt_iter++;
			}
		}
		printf("\n");
		closedir(dir);
	}
	return (0);
}
