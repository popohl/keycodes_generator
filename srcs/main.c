/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 11:32:23 by pohl              #+#    #+#             */
/*   Updated: 2021/09/14 19:26:06 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "main_structs.h"
#include "various_shit.h"
#include "config_initialisation.h"
#include "checkers.h"
#include "draw.h"
#include "keycodes.h"
#include "mlx.h"
#include <stdlib.h>

void	exit_program(t_config *config)
{
	mlx_destroy_image(config->mlx.mlx_ptr, config->mlx.win_ptr); 
	/* mlx_destroy_window(config->mlx.mlx_ptr, config->mlx.win_ptr); */ 
	exit(0);
}

int close(void *param)
{
	exit_program((t_config *)param);
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_config	*config;

	config = param;
	if (keycode == KC_H)
	{
		config->wscreen.origin.r -= config->wscreen.width / 10;
		draw_fractal(config);
	}
	if (keycode == KC_J)
	{
		config->wscreen.origin.i -= config->wscreen.width / 10;
		draw_fractal(config);
	}
	if (keycode == KC_K)
	{
		config->wscreen.origin.i += config->wscreen.width / 10;
		draw_fractal(config);
	}
	if (keycode == KC_L)
	{
		config->wscreen.origin.r += config->wscreen.width / 10;
		draw_fractal(config);
	}
	if (keycode == KC_U)
	{
		set_wscreen_width(config, config->wscreen.width /= 1.1);
		draw_fractal(config);
	}
	if (keycode == KC_I)
	{
		set_wscreen_width(config, config->wscreen.width *= 1.1);
		draw_fractal(config);
	}
	if (keycode == KC_W)
	{
		config->algo.julia_constant.i += 0.02;
		draw_fractal(config);
	}
	if (keycode == KC_S)
	{
		config->algo.julia_constant.i -= 0.02;
		draw_fractal(config);
	}
	if (keycode == KC_A)
	{
		config->algo.julia_constant.r -= 0.02;
		draw_fractal(config);
	}
	if (keycode == KC_D)
	{
		config->algo.julia_constant.r += 0.02;
		draw_fractal(config);
	}
	if (keycode == KC_UP_ARR)
	{
		config->algo.max_iteration += 100;
		draw_fractal(config);
	}
	if (keycode == KC_DOWN_ARR)
	{
		config->algo.max_iteration -= 100;
		draw_fractal(config);
	}
	if (keycode == KC_LEFT_ARR)
	{
		config->algo.type--;
		if (config->algo.type < 0)
			config->algo.type = 2;
		draw_fractal(config);
	}
	if (keycode == KC_RIGHT_ARR)
	{
		config->algo.type++;
		if (config->algo.type > 2)
			config->algo.type = 0;
		draw_fractal(config);
	}
	if (keycode == KC_R)
	{
		set_wscreen_width(config, 4.0);
		draw_fractal(config);
	}
	if (keycode == KC_Q)
	{
		exit_program(config);
	}
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	t_config	*config;
	t_ivector2	screen_coord;
	t_complex	world_coordinates;
	unsigned int	iterations;
	int				red_value;

	config = (t_config *)param;
	screen_coord.x = x;
	screen_coord.y = y;
	world_coordinates = get_coordinates(screen_coord, config->img.size,
			&config->wscreen);
	iterations = get_iteration_count(world_coordinates, &config->algo);
	red_value = ((double)iterations / config->algo.max_iteration) * 255;
	printf("(%d, %d) => (%f, %f) = %d its / %f max; red: %d\n", x, y, world_coordinates.r,
			world_coordinates.i, iterations, config->algo.max_iteration, red_value);
	return (0);
}

int	mouse_press(int button, int x, int y, void *param)
{
	t_config	*config;

	config = param;
	x = 0;
	y = 0;
	if (button == 4)
	{
		set_wscreen_width(config, config->wscreen.width /= 1.1);
		draw_fractal(config);
	}
	if (button == 5)
	{
		set_wscreen_width(config, config->wscreen.width *= 1.1);
		draw_fractal(config);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_config	config;

	if (!are_args_valid(argc, argv))
		return (1);
	if (!initialize_config(&config, argv))
		return (1);
	draw_fractal(&config);
	mlx_hook(config.mlx.win_ptr, 2, 1L<<0, key_press, &config);
	mlx_hook(config.mlx.win_ptr, 4, 1L<<2, mouse_press, &config);
	mlx_hook(config.mlx.win_ptr, 17, 1L<<0, close, &config);
	/* mlx_hook(config.mlx.win_ptr, 6, 1L<<13, mouse_move, &config); */
	mlx_loop(config.mlx.mlx_ptr);
	return (0);
}

void name_of_function() __attribute__((destructor));

void name_of_function()
{
    system("leaks fractol");
}
