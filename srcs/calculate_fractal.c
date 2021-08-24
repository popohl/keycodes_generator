/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:32:35 by pohl              #+#    #+#             */
/*   Updated: 2021/08/24 19:38:52 by pohl             ###   ########.fr       */
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

double	scaleBetween(int value, int original_max, t_ivector2 new_range)
{
	return ((double)((new_range.y - new_range.x) * value) /
			(double)(original_max) + new_range.x);
}

t_complex	get_coordinates(int x, int y, t_ivector2 screen_size, double escape_value)
{
	t_complex			coordinates;
	const t_ivector2	desired_range = {-(int)escape_value, (int)escape_value};

	coordinates.r = scaleBetween(x, screen_size.x, desired_range);
	coordinates.i = scaleBetween(y, screen_size.y, desired_range);
	return (coordinates);
}

/* int		main(void) */
/* { */
/* 	t_ivector2	screen_size = {SCREEN_SIZE, SCREEN_SIZE}; */
/* 	t_complex	coordinates; */
/* 	t_complex	initial_z = {0, 0}; */

/* 	for (int y = 0; y < screen_size.x; y++) */
/* 	{ */
/* 		for (int x = 0; x < screen_size.y; x++) */
/* 		{ */
/* 			coordinates = get_coordinates(x, y, screen_size); */
/* 			printf("%4d ", get_iteration_count(1, coordinates, initial_z)); */
/* 		} */
/* 		printf("\n"); */
/* 	} */
/* } */
