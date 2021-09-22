/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:55:58 by pohl              #+#    #+#             */
/*   Updated: 2021/09/22 17:16:36 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "config.h"
#include "algorithms.h"

void	zoom_center(double zoom_amount, t_config *config)
{
	set_wscreen_width(config, config->wscreen.width *= zoom_amount);
}

void	zoom_mouse(double zoom_amount, int x, int y, t_config *config)
{
	t_ivect2		screen_coord;
	double complex	old;
	double complex	new;

	screen_coord.x = x;
	screen_coord.y = y;
	old = get_coordinates(screen_coord, config->img.size,
			&config->wscreen);
	zoom_center(zoom_amount, config);
	new = get_coordinates(screen_coord, config->img.size,
			&config->wscreen);
	config->wscreen.origin.x += creal(old) - creal(new);
	config->wscreen.origin.y += cimag(new) - cimag(old);
}

void	set_zoom_value(double zoom_value, t_config *config)
{
	set_wscreen_width(config, 4.0 * pow(10, -zoom_value));
}
