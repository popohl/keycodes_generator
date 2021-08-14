/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:52:39 by pohl              #+#    #+#             */
/*   Updated: 2021/04/03 16:11:02 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*char_dst;
	unsigned char	*char_src;

	char_dst = ((unsigned char *)dst);
	char_src = ((unsigned char *)src);
	i = 0;
	if (dst > src)
	{
		while (i < len)
		{
			char_dst[len - 1 - i] = char_src[len - 1 - i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			char_dst[i] = char_src[i];
			i++;
		}
	}
	return (dst);
}
