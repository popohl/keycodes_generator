/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:02:15 by pohl              #+#    #+#             */
/*   Updated: 2021/04/03 16:12:53 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static char	*empty_string(void)
{
	char	*result;

	result = malloc(1);
	if (result)
		result[0] = 0;
	return (result);
}

static size_t	select_smallest(size_t num1, size_t num2)
{
	if (num1 > num2)
		return (num2);
	return (num1);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	result_len;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
		return (empty_string());
	result_len = select_smallest(ft_strlen(s + start), len);
	buffer = malloc(sizeof(*buffer) * result_len);
	if (!buffer)
		return (NULL);
	buffer[result_len] = 0;
	buffer = ft_strncpy(buffer, s + start, result_len);
	return (buffer);
}
