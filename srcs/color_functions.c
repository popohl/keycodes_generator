/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:47:23 by pohl              #+#    #+#             */
/*   Updated: 2021/09/07 14:02:47 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "various_shit.h"

int	get_color_value(int r, int g, int b)
{
	int		color;

	color = 0;
	color = color | (r << 16);
	color = color | (g << 8);
	color = color | b;
	return (color);
}
