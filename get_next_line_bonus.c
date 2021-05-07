/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:15:48 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/05/07 02:57:11 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	check_errors(int fd, char **line, int size, int is_start)
{
	if (BUFFER_SIZE <= 0)
		return (0);
	if (is_start)
		*line = malloc(sizeof(char));
	if (!(*line))
		return (0);
	if (size < 0 || fd < 0 || fd > MAX_VALUE)
	{
		free(*line);
		*line = 0;
		return (0);
	}
	if (is_start)
		(*line)[0] = '\0';
	return (1);
}

static int	maj_buffer(char *buf, int i)
{
	int	j;

	j = 0;
	while (j < BUFFER_SIZE - i)
	{
		buf[j] = buf[i + 1 + j];
		j++;
	}
	i = j;
	while (j <= BUFFER_SIZE)
	{
		buf[j] = '\0';
		j++;
	}
	return (i);
}

static int	index_pos(int size)
{
	if (size < 0)
		return (0);
	return (size);
}

int	get_next_line(int fd, char **line)
{
	static t_buffer	buff[MAX_VALUE];
	int				i;

	if (!line || !check_errors(fd, line, 1, 1))
		return (-1);
	if (buff[fd].size <= 0)
	{
		buff[fd].size = read(fd, buff[fd].content, BUFFER_SIZE);
		buff[fd].content[index_pos(buff[fd].size)] = '\0';
	}
	while (buff[fd].size > 0)
	{
		i = find_char_index(buff[fd].content, '\n');
		if (i >= 0)
		{
			*line = join_and_realloc(*line, buff[fd].content, i);
			buff[fd].size = maj_buffer(buff[fd].content, i);
			return (check_errors(fd, line, 1, 0));
		}
		*line = join_and_realloc(*line, buff[fd].content, BUFFER_SIZE + 1);
		buff[fd].size = read(fd, buff[fd].content, BUFFER_SIZE);
		buff[fd].content[index_pos(buff[fd].size)] = '\0';
	}
	return (check_errors(fd, line, buff[fd].size, 0) - 1);
}
