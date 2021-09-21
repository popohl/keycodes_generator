/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_updating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:54:36 by pohl              #+#    #+#             */
/*   Updated: 2021/09/16 13:55:49 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	set_wscreen_width(t_config *config, double width)
{
	double	ratio;

	ratio = (double)config->img.size.y / (double)config->img.size.x;
	config->wscreen.width = width;
	config->wscreen.height = config->wscreen.width * ratio;
}

void	add_on_key(int keycode, int goal_keycode, double *value, double to_add)
{
	if (keycode == goal_keycode)
		*value += to_add;
}

void	set_on_key(int keycode, int goal_keycode, int *value, int to_set)
{
	if (keycode == goal_keycode)
		*value = to_set;
}
