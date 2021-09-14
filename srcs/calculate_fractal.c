/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:32:35 by pohl              #+#    #+#             */
/*   Updated: 2021/09/14 07:40:59 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_structs.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>

static int	get_mandelbrot(t_complex coordinates, t_algorithm *algo)
{
	t_complex	z;
	t_complex	tmp;
	int			current_count;

	z.r = 0;
	z.i = 0;
	current_count = 0;
	while (pow(z.r, 2) + pow(z.i, 2) <= pow(algo->escape_value, 2)
		&& current_count < algo->max_iteration)
	{
		tmp.r = pow(z.r, 2) - pow(z.i, 2) + coordinates.r;
		tmp.i = z.r * z.i * 2.0 + coordinates.i;
		z.r = tmp.r;
		z.i = tmp.i;
		current_count++;
	}
	if (current_count == algo->max_iteration)
		return (0);
	return (current_count);
}

static int	get_julia(t_complex coordinates, t_algorithm *algo)
{
	t_complex	tmp;
	int			current_count;

	current_count = 0;
	while (pow(coordinates.r, 2) + pow(coordinates.i, 2)
		<= pow(algo->escape_value, 2)
		&& current_count < algo->max_iteration)
	{
		tmp.r = pow(coordinates.r, 2) - pow(coordinates.i, 2)
			+ algo->julia_constant.r;
		tmp.i = coordinates.r * coordinates.i * 2.0 + algo->julia_constant.i;
		coordinates.r = tmp.r;
		coordinates.i = tmp.i;
		current_count++;
	}
	if (current_count == algo->max_iteration)
		return (0);
	return (current_count);
}

int	get_iteration_count(t_complex coordinates, t_algorithm *algo)
{
	if (algo->type == MANDELBROT)
		return (get_mandelbrot(coordinates, algo));
	else if (algo->type == JULIA)
		return (get_julia(coordinates, algo));
	else
		return (-1);
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
