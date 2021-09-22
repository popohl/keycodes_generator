/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:41:23 by pohl              #+#    #+#             */
/*   Updated: 2021/09/22 16:15:39 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include <complex.h>
# include "config.h"

/*
** calculate_fractal.c
*/

double complex	get_coordinates(t_ivect2 screen_coord, t_ivect2 screen_size,
		t_world_screen *world_screen);
int	get_iteration_count(double complex coordinates, t_algorithm *algo);

/*
** values_updating.c
*/

void	set_wscreen_width(t_config *config, double width);
void	add_on_key(int keycode, int goal_keycode, double *value, double to_add);
void	set_on_key(int keycode, int goal_keycode, int *value, int to_set);

/*
** zoom.c
*/

void	zoom_center(double zoom_amount, t_config *config);
void	zoom_mouse(double zoom_amount, int x, int y, t_config *config);
void	set_zoom_value(double zoom_value, t_config *config);

#endif
