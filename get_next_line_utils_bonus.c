/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:22:02 by cbrito-l          #+#    #+#             */
/*   Updated: 2021/05/07 03:15:23 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

static char	*ft_realloc(char *str, int size)
{
	char	*new;
	int		i;

	if (size < ft_strlen(str))
		return (NULL);
	new = malloc(size * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && i < size)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

char	*join_and_realloc(char *str, char *buf, int size)
{
	int	i;
	int	j;
	int	n;

	n = ft_strlen(str);
	j = n + size + 1;
	str = ft_realloc(str, j);
	if (!str)
		return (NULL);
	i = 0;
	j = n;
	while (i < size)
	{
		str[j] = buf[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

int	find_char_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
