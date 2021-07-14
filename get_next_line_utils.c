/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:22:02 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/07/14 21:35:51 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_fill(char *dst, const char *src, char lim)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != lim)
	{
		dst[i] = src[i];
		i++;
	}
	if (lim == '\n')
	{
		dst[i] = '\n';
		dst[i + 1] = '\0';
	}
	else
		dst[i] = '\0';
}

int	ft_concat(char **line, char *buf, char lim)
{
	char	*new_line;
	int		len_line;
	int		len_buf;

	len_line = 0;
	len_buf = 0;
	if (*line)
		while ((*line)[len_line])
			len_line++;
	while (buf[len_buf] && buf[len_buf] != lim)
		len_buf++;
	new_line = malloc(sizeof(char) * (len_line + len_buf + 1));
	if (!new_line)
	{
		free(*line);
		*line = NULL;
		return (RETURN_LINE);
	}
	if (*line)
		ft_fill(new_line, *line, lim);
	ft_fill(&new_line[len_line], buf, lim);
	free(*line);
	*line = new_line;
	return (CONCAT_DONE);
}

char	*ft_update_save(char *save)
{
	char	*tmp;
	int		i;

	i = 0;
	while (save[i])
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	ft_fill(tmp, save, '\0');
	return (tmp);
}
