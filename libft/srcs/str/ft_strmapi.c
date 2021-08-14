/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:27:32 by pohl              #+#    #+#             */
/*   Updated: 2021/04/03 16:12:14 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*buffer;

	i = 0;
	while (s[i])
		i++;
	buffer = (char *)malloc(i + 1);
	if (buffer == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		buffer[i] = (*f)(i, s[i]);
		i++;
	}
	buffer[i] = 0;
	return (buffer);
}
