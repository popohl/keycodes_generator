/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:32:35 by pohl              #+#    #+#             */
/*   Updated: 2021/09/21 15:48:32 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <complex.h>
#include "mlx.h"
#include "config.h"

static int	get_mandelbrot(double complex coordinates, t_algorithm *algo)
{
	double complex	z;
	int				current_count;

	z = 0.0;
	current_count = 0;
	while (cabs(z) <= ESCAPE_VALUE && current_count < algo->max_iteration)
	{
		z = z * z + coordinates;
		current_count++;
	}
	if (current_count == algo->max_iteration)
		return (0);
	return (current_count);
}

static int	get_julia(double complex coordinates, t_algorithm *algo)
{
	int			current_count;

	current_count = 0;
	while (cabs(coordinates) <= ESCAPE_VALUE && current_count < algo->max_iteration)
	{
		coordinates = coordinates * coordinates + algo->julia_constant;
		current_count++;
	}
	if (current_count == algo->max_iteration)
		return (0);
	return (current_count);
}

static int	get_burning_julia(double complex coordinates, t_algorithm *algo)
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
		return (0);
	return (current_count);
}

static int	get_burning_ship(double complex coordinates, t_algorithm *algo)
{
	t_dvect2	z;
	t_dvect2	tmp;
	int			current_count;

	z.x = 0;
	z.y = 0;
	current_count = 0;
	while (pow(fabs(z.x), 2) + pow(fabs(z.y), 2) <= 4
		&& current_count < algo->max_iteration)
	{
		z.x = fabs(z.x);
		z.y = fabs(z.y);
		tmp.x = pow(z.x, 2) - pow(z.y, 2) + creal(coordinates);
		tmp.y = z.x * z.y * 2.0 + cimag(coordinates);
		z.x = tmp.x;
		z.y = tmp.y;
		current_count++;
	}
	if (current_count == algo->max_iteration)
		return (0);
	return (current_count);
}

static int	get_inverted_mandelbrot(double complex coordinates, t_algorithm *algo)
{
	double complex	z;
	int			current_count;

	z = 0.0;
	current_count = 0;
	while (cabs(z) <= ESCAPE_VALUE && current_count < algo->max_iteration)
	{
		z = z * z + 1 / coordinates;
		current_count++;
	}
	if (current_count == algo->max_iteration)
		return (0);
	return (current_count);
}

int	get_iteration_count(double complex coordinates, t_algorithm *algo)
{
	if (algo->type == MANDELBROT)
		return (get_mandelbrot(coordinates, algo));
	else if (algo->type == JULIA)
		return (get_julia(coordinates, algo));
	else if (algo->type == BURNING_SHIP)
		return (get_burning_ship(coordinates, algo));
	else if (algo->type == INVERSE_MANDELBROT)
		return (get_inverted_mandelbrot(coordinates, algo));
	else if (algo->type == BURNING_JULIA)
		return (get_burning_julia(coordinates, algo));
	else
		return (-1);
}

double complex	get_coordinates(t_ivect2 screen_coord, t_ivect2 screen_size,
		t_world_screen *world_screen)
{
	double complex	result;

	result = world_screen->origin.x + ((double)screen_coord.x / screen_size.x)
		* world_screen->width - world_screen->width / 2;
	result += (-world_screen->origin.y +
		((double)screen_coord.y / screen_size.y)
		* world_screen->height - world_screen->height / 2) * I;
	return (result);
}
