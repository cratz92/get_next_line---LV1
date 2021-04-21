/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:15:48 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/04/21 13:53:31 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
  ssize_t readstat;
  static char *store;
  char  *tmpstore;
  int storesize;
  int nlcheck;

  storesize = 0;
  tmpstore = malloc((BUFFER_SIZE + 1) * sizeof(char));
  if (!tmpstore)
    return (-1);
  
  readstat = read(fd, tmpstore, BUFFER_SIZE);
  if (!readstat || readstat == 0 || fd == 0 || BUFFER_SIZE <= 0)
    return (-1);
  
  storesize += readstat;
  store = ft_update_str(store, tmpstore);
  
  while (readstat != 0)
  {
    store = ft_update_str(store, tmpstore);
    nlcheck = ft_check_endline(store);
    if (nlcheck != 0)
      break ;

    readstat = read(fd, tmpstore, BUFFER_SIZE);
    if (!readstat)
      return (-1);
    
    storesize += readstat;

    

    
  }
}

char  *ft_get_line_update(char **line, char *src, int i)
{
  if (!(*line))
    free(line);
  line = malloc(sizeof())
}

int ft_check_endline(char *str)
{
  int i;

  if (!str)
    return (0);
  while (str[i] != '\0')
  {
    if (str[i] == '\n')
      return (i);
    i++;
  }
  return (0);
}


char  *ft_update_str(char *dest, char *src)
{
  int Destsize;
  int i;
  char *tmp;

  if (!dest || !src)
    return (0);
  tmp = malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 1));
  if (!tmp)
    return (0);
  Destsize = ft_strlen(dest);
  i = 0;
  while (src[i] != '\0')
  {
    dest[ Destsize + i] = src[i];
    i++;
  }
  dest[Destsize + i];
  return (dest);
}


int ft_strlen(char *str)
{
  int i;

  i = 0;
  if (!str)
    return (0);
  while (*str)
  {
    i++;
    str++;
  }
  return (i);
}


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