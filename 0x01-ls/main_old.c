#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define RESET_COLOR "\e[m"
#define MAKE_GREEN "\e[32m"
#define MAKE_BLUE "\e[36m"

int main(void)
{
	char *curr_dir = NULL;
	DIR *dp = NULL;
	struct dirent *dptr = NULL;
	unsigned int count = 0;
	long *ptr = NULL;
	struct winsize w;

	//to get the number of rows and column visible on terminal
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	// Fetch the environment variable PWD so as to get the
	// Current working directory
	curr_dir = getenv("PWD");
	if(NULL == curr_dir)
	{
		printf("\n ERROR : Could not get the working directory\n");
		return -1;
	}

	// Variable to hold number of files inside the directory
	int num_files = 0;
	// opne the directory
	dp = opendir((const char*)curr_dir);
	// Start reading the directory contents
	while(NULL != (dptr = readdir(dp)))
	{
		// Do not count the files begining with '.'
		if(dptr->d_name[0] != '.')
		num_files++;
	}
	// Our aim was to count the number of files/folders
	// inside the current working directory. Since its
	// done so close the directory.
	closedir(dp);

	// Restore the values back as we will be using them
	// later again
	dp = NULL;
	dptr = NULL;

	// Check that we should have at least one file/folder
	// inside the current working directory
	if(!num_files)
	{
		return 0;
	}
	else
	{
		// Allocate memory to hold the addresses of the
		// names of contents in current working directory
		ptr = malloc(num_files*8);
		if(NULL == ptr)
		{
			printf("\n Memory allocation failed\n");
			return -1;
		}
		else
		{
			// Initialize the memory by zeros
			memset(ptr,0,num_files*8);
		}
	}

	// Open the directory again
	dp = opendir((const char*)curr_dir);
	if(NULL == dp)
	{
		printf("\n ERROR : Could not open the working directory\n");
		free(ptr);
		return -1;
	}

	// Start iterating the directory and read all its contents
	// inside an array allocated above.
	unsigned int j = 0;
	for(count = 0; NULL != (dptr = readdir(dp)); count++)
	{
		if(dptr->d_name[0] != '.')
		{
			ptr[j] = (long)dptr->d_name;
			j++;
		}
	}

	// Start sorting the names alphabetically
	// Using bubble sorting here
	for(count = 0; count< num_files-1;count++)
	{
		for(j=count+1; j< (num_files);j++)
		{
			char *c = (char*)ptr[count];
			char *d = (char*)ptr[j];

			// Check that the two characters should be from same set
			if( ((*c >= 'a') && (*d >= 'a')) || ((*c <='Z') && (*d <='Z')) )
			{
				int i = 0;
				// If initial characters are same, continue comparing
				// the characters until a difference is found
				if(*c == *d)
				{
					while(*(c+i)==*(d+i))
					{
						i++;
					}
				}
				// Check if the earlier stored value is alphabetically
				// higher than the next value
				if(*(c+i) > *(d+i))
				{
					// If yes, then swap the values
					long temp = 0;
					temp = ptr[count];
					ptr[count] = ptr[j];
					ptr[j] = temp;
				}
			}
			else
			{
				// if the two beginning characters are not from
				// the same ASCII set then make them same and then
				// compare.
				int off_1=0, off_2=0;
				if(*c <= 'Z')
				{
					off_1 = 32;
				}
				if(*d <= 'Z')
				{
					off_2 = 32;
				}
				int i = 0;
				// After the character set are made same, check if the
				// beginning characters are same. If yes, then continue
				// searching until we find some difference.
				if(*c+ off_1 == *d + off_2)
				{
					while(*(c+off_1+i)==*(d+off_2+i))
					{
						i++;
					}
				}
				// After difference is found, check if a swap is required.
				if((*c + off_1+i) > (*d + off_2+i))
				{
					// If yes, go ahead and do the swap
					long temp = 0;
					temp = ptr[count];
					ptr[count] = ptr[j];
					ptr[j] = temp;
				}
			}
		}
	 }

	// Now the names are sorted alphabetically
	// Start displaying on console.
	for(count = 0; count< num_files; count++)
	{
		// Check if the file/folder is executable.
		if(!access((const char*)ptr[count],X_OK))
			{
				int fd = -1;
				struct stat st;
				fd = open((char*)ptr[count], O_RDONLY, 0);
				if(-1 == fd)
				{
					printf("\n Opening file/Directory failed\n");
					free(ptr);
					return -1;
				}

				fstat(fd, &st);
				if(S_ISDIR(st.st_mode))
				{
					// If folder, print in blue
					printf(MAKE_BLUE"%s	"RESET_COLOR,(char*)ptr[count]);
				}
				else
				{
					// If executable file, print in green
					printf(MAKE_GREEN"%s	"RESET_COLOR,(char*)ptr[count]);
				}
				close(fd);
			}
			else
			{
				// If normal file, print by the default way(black color)
				printf("%s	 ",(char*)ptr[count]);
			}
	}
	printf("\n");
	//Free the allocated memory
	free(ptr);
	return 0;
}
