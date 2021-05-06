/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:15:48 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/04/29 02:50:32 by cbrito-l         ###   ########.fr       */
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

static char	*ft_update_readtext(t_buffer *buff_, char *readText)
{
	char	*tmp;

	if (!readText)
	buff_->buf[buff_->nbr_chrs] = '\0';
	tmp = readText;
	if (readText[0] == 0)
		readText = ft_strdup(buff_->buf);
	else
	{
		free(readText);
		readText = ft_strjoin(buff_->buf, tmp);
		free(tmp);
	}
	return (readText);

}

static char	*ft_get_remaining_text(t_buffer *buff_, char *readText, char **line)
{

}

int	get_next_line(int fd, char **line)
{
	t_buffer	buff_;
	static char	*readText[MAX_SIZE];

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1
		|| fd == 1 || fd == 2)
		return (-1);
	buff_.nbr_chrs = 1;
	while (buff_.nbr_chrs && !ft_strchr(readText[fd], '\n'))
	{
		buff_.buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff_.buf)
			return (-1);
		buff_.nbr_chrs = read(fd, buff_.buf, BUFFER_SIZE);
		readText[fd] = ft_update_readtext(&buff_, readText[fd]);
	}
	readText[fd] = ft_get_remaining_text(&buff_, readText[fd], line);
}
