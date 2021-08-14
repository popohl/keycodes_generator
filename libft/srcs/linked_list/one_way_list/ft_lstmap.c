/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:46:25 by pohl              #+#    #+#             */
/*   Updated: 2021/03/30 18:22:10 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "one_way_list.h"

static void	ft_locallstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (lst && del)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = temp;
		}
	}
}

static int	new_lst_elt(t_list **alst, void *content)
{
	t_list	*new_element;
	t_list	*last_elt;

	new_element = malloc(sizeof(t_list));
	if (new_element == NULL)
		return (0);
	new_element->next = NULL;
	new_element->content = content;
	last_elt = *alst;
	while (last_elt && last_elt->next)
	{
		last_elt = last_elt->next;
	}
	if (last_elt)
		last_elt->next = new_element;
	else
		*alst = new_element;
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp;

	temp = lst;
	if (lst && (*f))
	{
		while (temp)
		{
			if (!new_lst_elt(&new_list, (*f)(temp->content)))
			{
				ft_locallstclear(&new_list, del);
				return (NULL);
			}
			temp = temp->next;
		}
		return (new_list);
	}
	return (NULL);
}
