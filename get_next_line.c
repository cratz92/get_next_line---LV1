/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:15:48 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/07/14 21:36:04 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	nl_save(char **line, char **save, int pos)
{
	char	*new_save;

	ft_fill(*line, *save, '\n');
	if (!(*save)[pos + 1])
	{
		free(*save);
		*save = NULL;
		return ;
	}
	new_save = ft_update_save(&(*save)[pos + 1]);
	free(*save);
	*save = new_save;
	if (!(*save))
	{
		free(*line);
		*line = NULL;
	}
}

int	ft_save(char **line, char **save)
{
	int	i;

	i = 0;
	if (!(*save))
		return (LINE_NOT_FULL);
	while ((*save)[i] && (*save)[i] != '\n')
		i++;
	if ((*save)[i] == '\n')
	{
		*line = malloc(sizeof(char) * (i + 2));
		nl_save(line, save, i);
		return (RETURN_LINE);
	}
	*line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (RETURN_LINE);
	ft_fill(*line, *save, '\0');
	free(*save);
	*save = NULL;
	return (LINE_NOT_FULL);
}

void	nl_buf(char **line, char *buf, char **save, int pos)
{
	int	i;

	i = pos + 1;
	if (!buf[i])
		return ;
	while (buf[i])
		i++;
	*save = malloc(sizeof(char) * (i + 1));
	if (!(*save))
	{
		free(*line);
		*line = NULL;
		return ;
	}
	ft_fill(*save, &buf[pos + 1], '\0');
}

int	ft_buf(char **line, char *buf, char **save)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (ft_concat(line, buf, buf[i]) == RETURN_LINE)
		return (RETURN_LINE);
	if (buf[i] == '\n')
	{
		nl_buf(line, buf, save, i);
		return (RETURN_LINE);
	}
	return (LINE_NOT_FULL);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	line = NULL;
	if (ft_save(&line, &save) == RETURN_LINE)
		return (line);
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret == ERROR)
		return (NULL);
	buf[ret] = '\0';
	while (ret)
	{
		ret = ft_buf(&line, buf, &save);
		if (ret == RETURN_LINE)
			return (line);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == ERROR)
			return (NULL);
		buf[ret] = '\0';
	}
	return (line);
}
