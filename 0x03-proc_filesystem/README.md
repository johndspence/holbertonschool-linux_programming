0. Hack the VM: Assignment
https://intranet.hbtn.io/projects/360

Write a script that finds a string in the heap of a running process, and replaces it.

Usage: read_write_heap.py pid search_string replace_stringwhere pid is the pid of the running process and strings are ASCII
The script should look only in the heap of the process
Output: you can print whatever you think is interesting
On usage error, print an error message on stdout and exit with status code 1


To compile looptest.c:
gcc -Wall -Werror -Wextra -pedantic looptest.c -o looptest

To get PID of looptest.c:
ps aux | grep ./looptest | grep -v grep

To modify the virtual memory being used by looptest.c
sudo python3 ./read_write_heap.py [PID] Holberton "New Text String"
