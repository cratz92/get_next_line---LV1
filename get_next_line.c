/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:15:48 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/05/10 03:58:14 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_get_index(char **save)
{
	int	i;

	i = 0;
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
		i++;
	return (i);
}

static int	ft_check_errors(int fd, char **line, int nb, int is_start)
{
	if (BUFFER_SIZE <= 0)
		return (0);
	if (is_start)
		*line = malloc(sizeof(char));
	if (!(*line))
		return (0);
	if (fd < 0 || nb < 0)
	{
		free(*line);
		*line = 0;
		return (0);
	}
	if (is_start)
		(*line)[0] = '\0';
	return (1);
}

static int	ft_read_input(int fd, t_buffer *buff, char **save)
{
	char	*tmp;

	buff->is_reading = true;
	while (buff->is_reading)
	{
		buff->r = read(fd, buff->content, BUFFER_SIZE);
		buff->content[buff->r] = '\0';
		if (!(save[fd]))
			save[fd] = ft_strdup(buff->content);
		else
		{
			tmp = ft_strjoin(save[fd], buff->content);
			free(save[fd]);
			save[fd] = ft_strdup(tmp);
		}
		if (ft_strchr(save[fd], '\n') || (buff->r <= 0))
			buff->is_reading = false;
	}
	free(buff->content);
	return (buff->r);
}

static int	ft_update_save(t_buffer *buff, char **save, char **line)
{
	char	*tmp;

	if (!strchr(*save, '\n'))
	{
		*line = ft_strdup(*save);
		free(*save);
		*save = 0;
		return (0);
	}
	else
	{
		buff->save_pos = ft_get_index(save);
		*line = ft_substr(*save, 0, buff->save_pos);
		tmp = ft_strdup(ft_strchr(*save, '\n') + 1);
		free(*save);
		*save = ft_strdup(tmp);
		return (1);
	}
}


int	get_next_line(int fd, char **line)
{
	static char	*save[MAX_SIZE];
	t_buffer	buff;

	if (!line || !ft_check_errors(fd, line, 1, 1))
		return (-1);
	buff.content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff.content)
		return (-1);
	buff.r = ft_read_input(fd, &buff, save);
	if ((buff.r < 0) || (buff.r == 0 && save[fd] == 0))
		return (ft_check_errors(fd, line, buff.r, 0) - 1);
	else
		return (ft_update_save(&buff, &save[fd], line));
}
