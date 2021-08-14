/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:51:37 by pohl              #+#    #+#             */
/*   Updated: 2021/04/03 16:21:38 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static bool	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (true);
		i++;
	}
	return (false);
}

int	result_len(const char *str, const char *set)
{
	int	i;
	int	char_count;

	i = 0;
	char_count = 0;
	while (str[i])
	{
		if (is_in_set(str[i], set))
			char_count++;
		i++;
	}
	return (i - char_count);
}

char	*ft_strtrim(const char *str, const char *set)
{
	char	*result;
	int		i;
	int		j;

	result = malloc(sizeof(*result) * result_len(str, set) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!is_in_set(str[i], set))
		{
			result[j] = str[i];
			j++;
		}
		i++;
	}
	return (result);
}
