/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:32:35 by pohl              #+#    #+#             */
/*   Updated: 2021/09/10 12:25:12 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_structs.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>

int	get_iteration_count(t_complex coordinates, double escape_value,
		int max_iterations)
{
	t_complex	z;
	t_complex	tmp;
	int			current_count;

	z.r = 0;
	z.i = 0;
	current_count = 0;
	while (pow(z.r, 2) + pow(z.i, 2) <= pow(escape_value, 2)
		&& current_count < max_iterations)
	{
		tmp.r = pow(z.r, 2) - pow(z.i, 2) + coordinates.r;
		tmp.i = z.r * z.i * 2.0 + coordinates.i;
		z.r = tmp.r;
		z.i = tmp.i;
		current_count++;
	}
	return (current_count);
}

t_complex	get_coordinates(t_ivector2 screen_coord, t_ivector2 screen_size,
		t_world_screen *world_screen)
{
	t_complex		result;

	result.r = world_screen->origin.r + ((double)screen_coord.x / screen_size.x)
		* world_screen->width - world_screen->width / 2;
	result.i = -world_screen->origin.i + ((double)screen_coord.y / screen_size.y)
		* world_screen->height - world_screen->height / 2;
	return (result);
}
