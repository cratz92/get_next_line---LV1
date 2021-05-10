# GET_NEXT_LINE (GNL)

The aim of this project is to make you code a function that returns a line
ending with a newline, read from a file descriptor.

# Introduction


We are allowed to use the following functions:
* read()
* malloc()
* free()

Note:. The respective prototypes can be found at the bottom of this file.

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

### Files that need to be submitted for the bonus:

* get_next_line_bonus.c
* get_next_line_utils_bonus.c
* get_next_line_bonus.h


# External functions 

Since we can't use the libft on this project, I had to include the following functions inside the utils file.

##### ft_strchr, ft_strlen, ft_strdup, ft_strjoin and ft_substr 

Each of these can be found inside Libft project.

## Allowed external functions

ssize_t read(int fd, void *buf, size_t n_bytes) 
~ ex. char *buffer; read(fd, buffer, 20); --> read 20 bytes or 20 chars

void  *malloc(size_t size) 
~ ex. buffer = malloc((20 + 1) * sizeof(char));

void free(void *ptr)
~ ex. free(buffer);

