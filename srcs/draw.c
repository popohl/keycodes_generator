/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulohl <pohl@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:50:01 by paulohl           #+#    #+#             */
/*   Updated: 2021/09/10 19:34:13 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "main_structs.h"
#include "various_shit.h"
#include "mlx.h"

int	get_color(int width, int height, t_config *cfg)
{
	t_complex		coordinates;
	unsigned int	iterations;
	int				red_value;
	t_ivector2		screen_coord;

	screen_coord.x = width;
	screen_coord.y = height;
	coordinates = get_coordinates(screen_coord, cfg->img.size, &cfg->wscreen);
	iterations = get_iteration_count(coordinates, &cfg->algo);
	red_value = cfg->algo.max_iteration / (double)iterations * 255;
	return (get_color_value(red_value, 0, 0));
}

void	reset_screen(t_image_info *img)
{
	int	i;
	int	length;

	i = 0;
	length = img->size.x * img->size.y;
	while (i < length)
	{
		img->data[i] = get_color_value(0, 0, 0);
		i++;
	}
}

void	draw_fractal(t_config *config)
{
	int				array_pos;
	int				height;
	int				width;

	reset_screen(&config->img);
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
