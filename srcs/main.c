/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 11:32:23 by pohl              #+#    #+#             */
/*   Updated: 2021/09/07 15:52:40 by paulohl          ###   ########.fr       */
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

int	key_press(int keycode, void *param)
{
	if (keycode == KC_H)
	{
		printf("hi!\n");
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
