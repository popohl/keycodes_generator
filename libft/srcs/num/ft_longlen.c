/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:35:34 by pohl              #+#    #+#             */
/*   Updated: 2021/09/22 18:49:58 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_longlen(long nbr)
{
	int	long_len;

	long_len = 0;
	if (nbr < 0)
		long_len++;
	else if (nbr == 0)
		return (1);
	else
		nbr = -nbr;
	while (nbr < 0)
	{
		nbr /= 10;
		long_len++;
	}
	return (long_len);
}
