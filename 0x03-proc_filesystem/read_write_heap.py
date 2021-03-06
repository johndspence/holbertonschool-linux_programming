#!/usr/bin/python3
'''
Locates and replaces the first occurrence of a string in the heap
of a process

Usage: ./read_write_heap.py PID search_string replace_by_string
Where:
- PID is the pid of the process
- search_string is the ASCII string you are looking to overwrite
- replace_by_string is the ASCII string you want to replace the
  search_string with
'''

import sys


def print_usage_and_exit():
    """Prints usage instructions and exits with 1"""
    print('Usage: {} pid search write'.format(sys.argv[0]))
    sys.exit(1)


def files_close():
    """Closes open files"""
    maps_file.close()
    mem_file.close()

# check usage get the pid, search string and write string from args
try:
    if len(sys.argv) != 4:
        print_usage_and_exit()
    pid = int(sys.argv[1])
    search_string = str(sys.argv[2])
    write_string = str(sys.argv[3])
    if (len(search_string) == 0 or len(write_string) == 0):
        print_usage_and_exit()
except Exception as e:
    print_usage_and_exit()

# Initialize the maps and mem files of the process
maps_filename = "/proc/{}/maps".format(pid)
print("[*] maps: {}".format(maps_filename))
mem_filename = "/proc/{}/mem".format(pid)
print("[*] mem: {}".format(mem_filename))

# try opening the maps file
try:
    maps_file = open('/proc/{}/maps'.format(pid), 'r')
except IOError as e:
    print("[ERROR] Can not open file {}:".format(maps_filename))
    print("I/O error({}): {}".format(e.errno, e.strerror))
    print_usage_and_exit()

# Check each line in maps to find heap and execute read, find, write
for line in maps_file:
    sline = line.split(' ')

    # check if we found the heap
    if sline[-1][:-1] != "[heap]":
        continue

    print("[*] Found [heap]:")  # Need to allow for no heap found

    # parse line
    addr = sline[0]
    perm = sline[1]
    offset = sline[2]
    device = sline[3]
    inode = sline[4]
    pathname = sline[-1][:-1]
    print("\tpathname = {}".format(pathname))
    print("\taddresses = {}".format(addr))
    print("\tpermisions = {}".format(perm))
    print("\toffset = {}".format(offset))
    print("\tinode = {}".format(inode))

    # check if there is read and write permission
    if perm[0] != 'r' or perm[1] != 'w':
        print("[*] {} does not have read/write permission".format(pathname))
        print_usage_and_exit()

    # get start and end of the heap in the virtual memory
    addr = addr.split("-")
    if len(addr) != 2:
        print("[*] Wrong addr format")
        maps_file.close()
        sys.exit(1)
    addr_start = int(addr[0], 16)
    addr_end = int(addr[1], 16)
    print("\tAddr start [{:x}] | end [{:x}]".format(addr_start, addr_end))

    # open and read mem
    try:
        mem_file = open(mem_filename, mode='rb+')
    except IOError as e:
        print("[ERROR] Can not open file {}:".format(mem_filename))
        print("I/O error({}): {}".format(e.errno, e.strerror))
        print_usage_and_exit()

    # read heap
    try:
        mem_file.seek(addr_start)
        heap = mem_file.read(addr_end - addr_start)
    except Exception:
        print("Can't find '{}'".format(addr_start))
        files_close()
        print_usage_and_exit()

    # find string
    try:
        i = heap.index(bytes(search_string, "ASCII"))
        print("[*] Found '{}' at {:x}".format(search_string, i))
    except Exception:
        print("Can't find '{}'".format(search_string))
        files_close()
        print_usage_and_exit()

    # write the new string
    try:
        print("[*] Writing '{}' at {:x}".format(write_string, addr_start + i))
        mem_file.seek(addr_start + i)
        adjusted_string = write_string.ljust(len(search_string))
        mem_file.write(bytes(adjusted_string, "ASCII"))
        files_close()
        sys.exit(0)
    except Exception:
        print("Can't write '{}'".format(write_string))
        files_close()
        print_usage_and_exit

    # close files
    files_close()
    sys.exit(1)
