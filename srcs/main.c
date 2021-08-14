/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:32:35 by pohl              #+#    #+#             */
/*   Updated: 2021/08/14 16:48:06 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "useful_structs.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>

#define SCREEN_SIZE 70
#define ESCAPE_VALUE 2
#define MAX_ITERATIONS 1500

int	get_iteration_count(int current_count, t_complex coordinates, t_complex z)
{
	t_complex	tmp;

	tmp.r = pow(z.r, 2) - pow(z.i, 2) + coordinates.r;
	tmp.i = z.r * z.i * 2.0 + coordinates.i;
	z.r = tmp.r;
	z.i = tmp.i;
	if (pow(z.r, 2) + pow(z.i, 2) > pow(ESCAPE_VALUE, 2)
			|| current_count > MAX_ITERATIONS)
		return (current_count);
	return (get_iteration_count(current_count + 1, coordinates, z));
}

/* #define RANGE_CHANGE(x,a,b,min,max) ((b-a)*(x-min)/(max-min))+a */
double	scaleBetween(int value, int original_max, t_ivector2 new_range)
{
	return ((double)((new_range.y - new_range.x) * value) /
			(double)(original_max) + new_range.x);
}

static t_complex	get_coordinates(int x, int y, t_ivector2 screen_size)
{
	t_complex			coordinates;
	const t_ivector2	desired_range = {-ESCAPE_VALUE, ESCAPE_VALUE};

	coordinates.r = scaleBetween(x, screen_size.x, desired_range);
	coordinates.i = scaleBetween(y, screen_size.y, desired_range);
	return (coordinates);
}

int		main(void)
{
	t_ivector2	screen_size = {SCREEN_SIZE, SCREEN_SIZE};
	t_complex	coordinates;
	t_complex	initial_z = {0, 0};
	const char	*draw_chars = "@%#*+=-:. ";

	for (int y = 0; y < screen_size.x; y++)
	{
		for (int x = 0; x < screen_size.y; x++)
		{
			coordinates = get_coordinates(x, y, screen_size);
			/* printf("(%4.1f, %4.1f) ", coordinates.x, coordinates.y); */
			printf("%4d ", get_iteration_count(1, coordinates, initial_z));
		}
		printf("\n");
	}
}
