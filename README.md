# GET_NEXT_LINE (GNL)

The aim of this project is to make you code a function that returns a line
ending with a newline, read from a file descriptor.

# Introduction



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


