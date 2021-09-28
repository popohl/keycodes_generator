/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractal_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:16:20 by pohl              #+#    #+#             */
/*   Updated: 2021/09/28 16:20:27 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <complex.h>
#include "mlx.h"
#include "config.h"

int	get_glynn(double complex coordinates, t_algorithm *algo)
{
	int	current_count;

	current_count = 0;
	while (cabs(coordinates) <= ESCAPE_VALUE && current_count
		< algo->max_iteration)
	{
		coordinates = cpow(coordinates, 1.5) + 0.2;
		current_count++;
	}
	if (current_count == algo->max_iteration)
		return (-1);
	return (current_count);
}

int	get_burning_julia(double complex coordinates, t_algorithm *algo)
{
	t_dvect2	z;
	t_dvect2	tmp;
	int			current_count;

	z.x = creal(coordinates);
	z.y = cimag(coordinates);
	current_count = 0;
	while (pow(fabs(z.x), 2) + pow(fabs(z.y), 2) <= 4
		&& current_count < algo->max_iteration)
	{
		z.x = fabs(z.x);
		z.y = fabs(z.y);
		tmp.x = pow(z.x, 2) - pow(z.y, 2) + creal(algo->julia_constant);
		tmp.y = z.x * z.y * 2.0 + cimag(algo->julia_constant);
		z.x = tmp.x;
		z.y = tmp.y;
		current_count++;
	}
	if (current_count == algo->max_iteration)
		return (-1);
	return (current_count);
}

int	get_inv_mandelbrot(double complex coordinates, t_algorithm *algo)
{
	double complex	z;
	int				current_count;

	z = 0.0;
	current_count = 0;
	while (cabs(z) <= ESCAPE_VALUE && current_count < algo->max_iteration)
	{
		z = z * z + 1 / coordinates;
		current_count++;
	}
	if (current_count == algo->max_iteration)
		return (-1);
	return (current_count);
}
