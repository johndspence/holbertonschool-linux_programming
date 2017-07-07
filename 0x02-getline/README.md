# 0x02. C - Static variables, getline
System programming & Algorithm ― Linux programming

https://intranet.hbtn.io/projects/322

### Task 0 - _getline

Write a function that reads an entire line from a file descriptor.

Prototype : char *_getline(const int fd)

- Where fd is the file descriptor to read from
- If there are no more lines to return, or if there is an error, the function should return NULL
- The function returns a null-terminated string that does not include the newline character
- Your header file _getline.h should define a macro called READ_SIZE. This macro defines the number of bytes you will read each time you will call read: read(fd, buffer, READ_SIZE)
You are not allowed to read more or less than READ_SIZE bytes at once from fd
- You can assume that fd will always be the same
