/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:13:54 by pohl              #+#    #+#             */
/*   Updated: 2021/03/30 18:18:10 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	num_of_char(int n)
{
	int				i;
	unsigned int	num;

	i = 1;
	num = n;
	if (n < 0)
	{
		i = 2;
		num = -n;
	}
	while (num > 9)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			buffer[42];
	unsigned int	num;
	int				i;

	i = num_of_char(n);
	num = n;
	if (n < 0)
	{
		num = -n;
		buffer[0] = '-';
	}
	buffer[i] = 0;
	buffer[i - 1] = '0';
	while (num > 0)
	{
		i--;
		buffer[i] = num % 10 + 48;
		num /= 10;
	}
	i = 0;
	while (buffer[i])
		i++;
	write(fd, buffer, i);
}
