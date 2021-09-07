/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:32:35 by pohl              #+#    #+#             */
/*   Updated: 2021/09/07 13:12:22 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "useful_structs.h"
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

static double	scale_between(int value, int original_max, t_complex new_range)
{
	return ((double)((new_range.i - new_range.r) * value) /
		(double)(original_max) + new_range.r);
}

t_complex	get_coordinates(int x, int y, t_ivector2 screen_size)
{
	t_complex		coordinates;
	const t_complex	desired_range = {-2, 2};

	coordinates.r = scale_between(x, screen_size.x, desired_range);
	coordinates.i = scale_between(y, screen_size.y, desired_range);
	return (coordinates);
}
