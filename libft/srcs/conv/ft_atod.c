/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:35:57 by pohl              #+#    #+#             */
/*   Updated: 2021/09/22 15:21:14 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

static int	read_units(const char *str, int i, double *result)
{
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		*result *= 10;
		*result += str[i] - 48;
		i++;
	}
	return (i);
}

static double	read_decimals(const char *str, int i)
{
	int		decimal_power;
	double	result;
	double	tmp;

	decimal_power = 0;
	result = 0.0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		decimal_power++;
		tmp = (double)(str[i] - 48) / pow(10, decimal_power);
		result += tmp;
		i++;
	}
	return (result);
}

double	ft_atod(const char *str)
{
	unsigned int	i;
	double			result;
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
	i = read_units(str, i, &result);
	if (str[i] == '.')
		result += read_decimals(str, i + 1);
	return (result * sign);
}
