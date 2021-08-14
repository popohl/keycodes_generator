/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:52:52 by pohl              #+#    #+#             */
/*   Updated: 2021/04/17 14:41:23 by ft               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

#define GNL_ERROR -1
#define GNL_EOF 0
#define GNL_LINE 1

static char	*ft_strjoin_freefirst(char const *s1, char const *s2)
{
	char	*buffer;

	buffer = ft_strjoin(s1, s2);
	if (s1)
		free((void *)s1);
	return (buffer);
}

static int	found_new_line(char **rest, char **line)
{
	long	n;

	if (!*rest)
	{
		*rest = (char *)malloc(sizeof(**rest));
		if (!*rest)
			return (GNL_ERROR);
		(*rest)[0] = 0;
	}
	n = ft_strchr(*rest, '\n') - *rest;
	if (n >= 0)
	{
		*line = (char *)malloc(sizeof(**line) * (n + 1));
		if (*line)
		{
			ft_strncpy(*line, *rest, n);
			*rest = ft_strreplace(*rest, *rest + n + 1);
			if (*rest)
				return (1);
		}
		return (GNL_ERROR);
	}
	return (0);
}

int			final_return(char **line, char **rest, char *temp)
{
	if (temp)
		free(temp);
	if (rest)
	{
		*line = ft_strdup(*rest);
		free(*rest);
		*rest = 0;
		if (*line)
			return (0);
	}
	return (GNL_ERROR);
}

int			read_input(char **line, char **rest, char *temp, int fd)
{
	int	n;

	ft_bzero(temp, sizeof(*temp) * BUFFER_SIZE + 1);
	n = read(fd, temp, BUFFER_SIZE);
	if (n > 0)
	{
		temp[n] = 0;
		*rest = ft_strjoin_freefirst(*rest, temp);
		if (!*rest)
		{
			free(temp);
			return (GNL_ERROR);
		}
		return (1);
	}
	else if (n == 0)
		return (final_return(line, rest, temp));
	else
	{
		free(temp);
		return (GNL_ERROR);
	}
}

int			get_next_line(int fd, char **line)
{
	static char	*rest = NULL;
	char		*temp;
	int			n;

	if (read(fd, 0, 0) == -1 || !line || BUFFER_SIZE <= 0)
		return (GNL_ERROR);
	temp = (char *)malloc(sizeof(*temp) * BUFFER_SIZE + 1);
	if (!temp)
		return (GNL_ERROR);
	while ((found_new_line(&rest, line)) == 0)
	{
		n = read_input(line, &rest, temp, fd);
		if (n == -1)
			return (GNL_ERROR);
		else if (n == 0)
			return (GNL_EOF);
	}
	free(temp);
	if (rest)
		return (GNL_LINE);
	return (GNL_ERROR);
}
