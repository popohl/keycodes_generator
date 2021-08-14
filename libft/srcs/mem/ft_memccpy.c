/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:42:23 by pohl              #+#    #+#             */
/*   Updated: 2019/10/25 14:57:10 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (((unsigned char *)src)[i] != (unsigned char)c && i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	if (i < n)
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	if (i == n)
		return (0);
	return (dest + i + 1);
}
