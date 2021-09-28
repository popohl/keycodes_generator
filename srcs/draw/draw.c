/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulohl <pohl@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:50:01 by paulohl           #+#    #+#             */
/*   Updated: 2021/09/28 14:56:35 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "draw.h"
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

double	calc_percentage(int width, int height, t_config *cfg, t_image_info *img)
{
	double complex	coordinates;
	int				iterations;
	t_ivect2		screen_coord;

	screen_coord.x = width;
	screen_coord.y = height;
	coordinates = get_coordinates(screen_coord, img->size, &cfg->wscreen);
	iterations = get_iteration_count(coordinates, &cfg->algo);
	if (iterations == -1)
		return (-1);
	return ((double)iterations / cfg->algo.max_iteration);
}

int	get_color(int width, int height, t_config *cfg, t_image_info *img)
{
	double	percentage;
	int		red;
	int		green;
	int		blue;

	percentage = calc_percentage(width, height, cfg, img);
	if (percentage == -1)
		return (COLOR_BLACK);
	return (hsv_to_rgb(percentage * 360, 1, 1));
	red = 0;
	green = 0;
	blue = 0;
	if (percentage > 0.1)
		red = ((percentage - 0.1) / 0.9) * 255;
	if (percentage <= 0.3)
		blue = (percentage / 0.4) * 255;
	else if (percentage < 0.6)
		blue = 255 - ((percentage - 0.4) / 0.2) * 255;
	if (percentage > 0.6)
	{
		green = ((percentage - 0.6) / 0.4) * 255;
	}
	return (get_int_color_from_rgb(red, green, blue));
}

void	fill_img(t_config *config, t_image_info *img)
{
	int				array_pos;
	int				height;
	int				width;

	height = 0;
	while (height < img->size.y)
	{
		width = 0;
		while (width < img->size.x)
		{
			array_pos = height * img->size_line + width;
			img->data[array_pos] = get_color(width, height, config, img);
			width++;
		}
		height++;
	}
}

void	draw_fractal(t_config *config)
{
	mlx_clear_window(config->mlx.mlx_ptr, config->mlx.win_ptr);
	mlx_put_image_to_window(config->mlx.mlx_ptr, config->mlx.win_ptr,
		config->img.img_ptr, 0, 0);
	fill_img(config, &config->img);
	mlx_put_image_to_window(config->mlx.mlx_ptr, config->mlx.win_ptr,
		config->img.img_ptr, 0, 0);
	if (config->display_hud)
		draw_hud(config);
}
