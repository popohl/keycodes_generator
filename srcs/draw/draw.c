/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulohl <pohl@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:50:01 by paulohl           #+#    #+#             */
/*   Updated: 2021/09/16 15:55:22 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "algorithms.h"

int	get_int_color_from_rgb(int r, int g, int b)
{
	int		color;

	color = 0;
	color = color | (r << 16);
	color = color | (g << 8);
	color = color | b;
	return (color);
}

double calculate_percentage(int width, int height, t_config *cfg)
{
	double complex	coordinates;
	unsigned int	iterations;
	t_ivect2		screen_coord;

	screen_coord.x = width;
	screen_coord.y = height;
	coordinates = get_coordinates(screen_coord, cfg->img.size, &cfg->wscreen);
	iterations = get_iteration_count(coordinates, &cfg->algo);
	return ((double)iterations / cfg->algo.max_iteration);
}

int	get_color(int width, int height, t_config *cfg)
{
	double	percentage;
	int		red;
	int		green;
	int		blue;

	percentage = calculate_percentage(width, height, cfg);
	red = 0;
	green = 0;
	blue = 0;
	if (percentage > 0.2)
		red = ((percentage - 0.2) / 0.8) * 255;
	if (percentage <= 0.4)
		blue = (percentage / 0.4) * 255;
	else if (percentage < 0.6)
		blue = 255 - ((percentage - 0.4) / 0.2) * 255;
	if (percentage > 0.6)
	{
		green = ((percentage - 0.6) / 0.4) * 255;
	}
	return (get_int_color_from_rgb(red, green, blue));
}

void	draw_fractal(t_config *config)
{
	int				array_pos;
	int				height;
	int				width;

	mlx_clear_window(config->mlx.mlx_ptr, config->mlx.win_ptr);
	mlx_put_image_to_window(config->mlx.mlx_ptr, config->mlx.win_ptr,
		config->img.img_ptr, 0, 0);
	height = 0;
	while (height < config->img.size.y)
	{
		width = 0;
		while (width < config->img.size.x)
		{
			array_pos = height * config->img.size_line + width;
			config->img.data[array_pos] = get_color(width, height, config);
			width++;
		}
		height++;
	}
	mlx_put_image_to_window(config->mlx.mlx_ptr, config->mlx.win_ptr,
		config->img.img_ptr, 0, 0);
}
