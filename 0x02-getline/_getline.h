#ifndef getlinehdr
#define getlinehdr

#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#define READ_SIZE 1
#define BUF_SIZE 256

void *_realloc(void *ptr, size_t size);
char *_getline(const int fd);

#endif /* getlinehdr */
