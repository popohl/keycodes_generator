/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulohl <pohl@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:41:15 by paulohl           #+#    #+#             */
/*   Updated: 2021/09/07 12:45:47 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	are_args_valid(int argc, char **argv)
{
	if (argc != 1)
		return (false);
	if (argv[0] == 0)
		return (false);
	return (true);
}
