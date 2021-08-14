/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulohl <pohl@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:31:46 by paulohl           #+#    #+#             */
/*   Updated: 2021/03/31 11:39:12 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strreplace(char *original, const char *new_value)
{
	char	*to_return;

	free(original);
	to_return = ft_strdup(new_value);
	return (to_return);
}
