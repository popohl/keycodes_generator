/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:24:02 by pohl              #+#    #+#             */
/*   Updated: 2021/04/03 16:11:42 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int		str_len;
	int		i;
	char	*buffer;

	str_len = 0;
	i = 0;
	if (str)
		while (str[str_len])
			str_len++;
	else
		str_len = 0;
	buffer = (char *)malloc(sizeof(*buffer) * (str_len + 1));
	if (!buffer)
		return (0);
	while (i < str_len)
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = 0;
	return (buffer);
}
