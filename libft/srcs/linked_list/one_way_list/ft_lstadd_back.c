/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:28:39 by pohl              #+#    #+#             */
/*   Updated: 2021/03/16 13:08:41 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "one_way_list.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last_elt;

	last_elt = *alst;
	while (last_elt && last_elt->next)
	{
		last_elt = last_elt->next;
	}
	if (last_elt)
		last_elt->next = new;
	else
		*alst = new;
}
