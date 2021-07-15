/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:17:54 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/07/15 16:29:00 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_SIZE
#  define MAX_SIZE 4096
# endif

# define ERROR -1
# define RETURN_LINE 0
# define LINE_NOT_FULL 1
# define SUCESS_CONCAT 1

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>
# include <limits.h>

/*
** get_next_line.c
*/

static void	extra_save(char **line, char **save, int pos);
int			ft_check_save(char **line, char **save);
static void	extra_buf(char **line, char *buf, char **save, int pos);
int			ft_check_buf(char **line, char *buf, char **save);
char		*get_next_line(int fd);

/*
** get_next_line_utils.c
*/
char		*ft_update_save(char *save);
void		ft_strcpy_gnl(char *dst, const char *src, char lim);
int			ft_concat(char **line, char *buf, char lim);

#endif