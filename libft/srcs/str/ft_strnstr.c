/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:17:42 by pohl              #+#    #+#             */
/*   Updated: 2021/03/30 18:23:13 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (needle[i])
		i++;
	if (i == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] && needle[j] == haystack[i + j] && i + j < len)
				j++;
			if (needle[j] == 0)
				return ((char *)haystack + i);
		}
		if (++i == len)
			return (0);
	}
	return (0);
}
