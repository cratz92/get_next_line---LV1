/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:15:48 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/04/19 19:36:22 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    
FILE *fp = NULL;

fp = fdopen(fd, "r");
if (fp == NULL)
{
    /* ERROR MESSAGE */
    return (-1);
}


}
char *filename = "TEST.txt";

fopen(filename, "w");

/*

ssize_t read(int fd, void *buf, size_t nbyte)
---> attempts to read nbyte bytes of data from obj referenced by the fd into the buffer pointed to by buf.
return, number of bytes actually read is returned. upon EOF, returns 0. otherwise, returns -1 indicating an error.

BUFFER_SIZE from compilation 

FILE *fopen(const char *restrict name, const char *restrict mode)

modes: "w" - write ops, current contents are discarded / "a" - append ops, write at EOF
        "r" - read ops
        "w+" / "a+" / "r+"

fclose( *file pointer ) 

file positioning

--|-> finding out where you are in a file
  |-> moving to a given point in a file

*/