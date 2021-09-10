/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 11:32:23 by pohl              #+#    #+#             */
/*   Updated: 2021/09/10 19:26:02 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "main_structs.h"
#include "various_shit.h"
#include "mlx.h"
#include "config_initialisation.h"
#include "checkers.h"
#include "draw.h"
#include "keycodes.h"
#include <stdlib.h>

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
		config->wscreen.width /= 1.5;
		config->wscreen.height = config->wscreen.width *
			((double)config->img.size.y/ config->img.size.x);
		draw_fractal(config);
	}
	if (keycode == KC_I)
	{
		config->wscreen.width *= 1.5;
		config->wscreen.height = config->wscreen.width *
			((double)config->img.size.y/ config->img.size.x);
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
		config->algo.escape_value -= 0.1;
		draw_fractal(config);
	}
	if (keycode == KC_RIGHT_ARR)
	{
		config->algo.escape_value += 0.1;
		draw_fractal(config);
	}
	if (keycode == KC_SPACE)
	{
		draw_fractal(config);
	}
	if (keycode == KC_Q)
	{
		exit(0);
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
	/* mlx_string_put(config.mlx.mlx_ptr, config.mlx.win_ptr, 50, 50, 0x00ffffff, "Hi there!"); */
	mlx_hook(config.mlx.win_ptr, 2, 1L<<0, key_press, &config);
	mlx_loop(config.mlx.mlx_ptr);
	return (0);
}
