/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 11:32:23 by pohl              #+#    #+#             */
/*   Updated: 2021/08/24 19:45:10 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_structs.h"
#include "various_shit.h"
#include "mlx.h"
#include <stdio.h>

void	draw_weird_shit(t_config *config)
{
	t_complex		coordinates;
	t_complex		initial_z;
	unsigned int	iterations;

	initial_z.r = 0;
	initial_z.i = 0;
	for (int height = 0; height < config->img.size.y; height++)
	{
		for (int width = 0; width < config->img.size.x; width++)
		{
			coordinates = get_coordinates(width, height, config->img.size, config->algo.escape_value);
			iterations = get_iteration_count(coordinates,
					config->algo.escape_value, config->algo.max_iterations);
			config->img.data[height * config->img.size_line + width] =
				hsv_to_rgb((double)iterations / config->algo.max_iterations * 360, 1, 1);
				/* get_color_value(config->algo.max_iterations / (double)iterations * 255, 0, 0); */
		}
	}
	mlx_put_image_to_window(config->mlx.mlx_ptr, config->mlx.win_ptr, config->img.img_ptr, 0, 0);
}

int	main(void)
{
	t_config	config;

	config.img.size.x = 1000;
	config.img.size.y = 1000;
	config.mlx.mlx_ptr = mlx_init();
	config.mlx.win_ptr = mlx_new_window(config.mlx.mlx_ptr, config.img.size.x, config.img.size.y, "Fractol");
	config.img.img_ptr = mlx_new_image(config.mlx.mlx_ptr, config.img.size.x, config.img.size.y);
	config.img.data = (int *)mlx_get_data_addr(config.img.img_ptr, 
			&config.img.img_depth, &config.img.size_line, &config.img.endian);
	config.img.size_line /= 4;
	config.algo.escape_value = 2.0;
	config.algo.max_iterations = 5000;
	draw_weird_shit(&config);
	/* mlx_string_put(mlx, window, 50, 50, 0x00ffffff, "Hi there"); */
	/* mlx_hook(config.mlx.win_ptr, int x_event, int x_mask, int (*funct)(), &config); */
	mlx_loop(config.mlx.mlx_ptr);
	return (0);
}
