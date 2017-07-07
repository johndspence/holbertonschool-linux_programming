#include "_getline.h"

/**
 * _realloc - function changes the size of the memory block pointed to by ptr
 * to size bytes.
 *
 * @ptr: Memory block to be increased.
 * @size: Number of bytes by which to increase memory block.
 *
 * Return: A pointer to reallocated memory.
 */
void *_realloc(void *ptr, size_t size)
{
	char *new_ret_ln;

	new_ret_ln = malloc(sizeof(char) * size);
	if (new_ret_ln)
	{
		memcpy(new_ret_ln, ptr, size);
		free(ptr);
		return (new_ret_ln);
	}
	else
	{
		return (NULL);
	}
}

/**
 * _getline - Reads an entire line from a file descriptor.
 *
 * @fd: The file descriptor.
 *
 * Return: On error or no more lines to read, function returns NULL.  Otherwise
 * returns a null-terminated string excluding the newline buf.
 */
char *_getline(const int fd)
{
	int i;
	char buf;
	char *ret_ln;
	size_t ret_ln_sz;

	ret_ln_sz = BUF_SIZE;
	ret_ln = malloc(sizeof(char) * ret_ln_sz);
	if (ret_ln == NULL)
	{
		return (NULL);
	}
	buf = '\0';
	for (i = 0; buf != '\n'; i++)
	{
		if ((read(fd, &buf, READ_SIZE) == 0))
		{
			free(ret_ln);
			return (NULL);
		}
		if (i >= (int)ret_ln_sz)
		{
			ret_ln_sz = ret_ln_sz + 1;
			ret_ln = _realloc(ret_ln, ret_ln_sz);
			if (ret_ln == NULL)
			{
				return (NULL);
			}
		}
		ret_ln[i] = buf;
	}
	ret_ln[i - 1] = '\0';
	return (ret_ln);
}
