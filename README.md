# GET_NEXT_LINE (GNL)

The aim of this project is to make you code a function that returns a line
ending with a newline, read from a file descriptor.

# Introduction


We are allowed to use the following functions:
* read()
* malloc()
* free()


### Main function prototype

```c
int get_next_line(int fd, char **line)

```
### Return value

* 1  --> line has been read
* 0  --> reach EOF (end of file)
* -1 --> error found


### Compilation formula

```c
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c
```

**BUFFER_SIZE** should be defined by the evaluator


# Mandatory Part

### Files that need to be submitted:

* get_next_line.c
* get_next_line_utils.c
* get_next_line.h

# External functions prototypes

ssize_t read(int fd, void *buf, size_t n_bytes) 
~ ex. char *buffer; read(fd, buffer, 20); --> read 20 bytes or 20 chars

void  *malloc(size_t size) 
~ ex. buffer = malloc((20 + 1) * sizeof(char));

void free(void *ptr)
~ ex. free(buffer);

