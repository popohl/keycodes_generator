/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulohl <pohl@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:50:01 by paulohl           #+#    #+#             */
/*   Updated: 2021/09/07 14:05:23 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "main_structs.h"
#include "various_shit.h"
#include "mlx.h"

int	get_color(int width, int height, t_config *config)
{
	t_complex		coordinates;
	unsigned int	iterations;
	int				red_value;

	coordinates = get_coordinates(width, height, config->img.size);
	iterations = get_iteration_count(coordinates,
			config->algo.escape_value, config->algo.max_iterations);
	red_value = config->algo.max_iterations / (double)iterations * 255;
	return (get_color_value(red_value, 0, 0));
}

void	draw_fractal(t_config *config)
{
	int				array_pos;
	int				height;
	int				width;

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
