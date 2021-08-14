/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:35:34 by pohl              #+#    #+#             */
/*   Updated: 2021/03/30 18:20:38 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_intlen(int nbr)
{
	int	int_len;

	int_len = 0;
	if (nbr < 0)
		int_len++;
	else if (nbr == 0)
		return (1);
	else
		nbr = -nbr;
	while (nbr < 0)
	{
		nbr /= 10;
		int_len++;
	}
	return (int_len);
}
