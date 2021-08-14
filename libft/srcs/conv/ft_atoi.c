/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:53:47 by pohl              #+#    #+#             */
/*   Updated: 2021/03/30 18:22:30 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	long			result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] && ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		if (result > (long)INT_MAX || result < (long)INT_MIN)
			return (-1);
		i++;
	}
	return (result * sign);
}
