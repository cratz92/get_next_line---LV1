/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:15:48 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/04/22 07:03:13 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_write(t_buffer *buff_, char *readText, char **line)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = ft_strdup(readText);
	tmp[buff_->save_pos] = '\0';
	if (tmp[0] == '\0')
		*line = ft_strdup("");
	else
		*line = ft_strdup(tmp);
	while (readText[i])
		i++;
	free(tmp);
	return (i);
}

static size_t	ft_get_elememt(t_buffer *buff_, char *readText)
{
	buff_->save_pos = 0;
	if (readText[0] == '\0')
	{
		buff_->flag_ = false;
		return (0);
	}
	while (readText[buff_->save_pos])
	{
		if (readText[buff_->save_pos] == '\n')
		{
			buff_->flag_ = true;
			break ;
		}
		buff_->save_pos++;
		buff_->flag_ = false;
	}
	return (buff_->save_pos);
}

static char	*ft_get_remaining_text(t_buffer *buff_, char *readText, char **line)
{
	char	*tmp;
	int		size;

	buff_->save_pos = ft_get_elememt(buff_, readText);
	size = ft_write(buff_, readText, line);
	if (readText[buff_->save_pos] == '\0')
	{
		free(readText);
		readText = NULL;
		return (readText);
	}
	free(readText);
	tmp = ft_substr(readText, buff_->save_pos + 1, size - (buff_->save_pos) - 1);
	free(buff_->buf);
	buff_->buf = 0;
	return (tmp);
}

static char	*ft_update_readtext(t_buffer *buff_, char *readText)
{
	char	*tmp;

	buff_->buf[buff_->r] = '\0';
	if (!readText)
		readText = ft_strdup(buff_->buf);
		
	else
	{
		tmp = ft_strjoin(readText, buff_->buf);
		free(readText);
		return (tmp);
	}
	return (readText);
}

int	get_next_line(int fd, char **line)
{
	t_buffer	buff_;
	static char	*readText;

	buff_.buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1
		|| fd == 1 || fd == 2 || !buff_.buf)
		return (-1);
	buff_.r = read(fd, buff_.buf, BUFFER_SIZE);
	readText[fd] = ft_update_readtext(&buff_, readText[fd]);
	while (!ft_strchr(buff_.buf, '\n') && buff_.r)
	{
		buff_.r = read(fd, buff_.buf, BUFFER_SIZE);
		readText[fd] = ft_update_readtext(&buff_, readText[fd]);
	}
	readText[fd] = ft_get_remaining_text(&buff_, readText[fd], line);
	if (buff_.flag_)
		return (1);
	else
		return (0);
}
