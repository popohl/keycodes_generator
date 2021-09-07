/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 11:32:23 by pohl              #+#    #+#             */
/*   Updated: 2021/09/07 13:16:06 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "main_structs.h"
#include "various_shit.h"
#include "mlx.h"
#include "config_initialisation.h"
#include "checkers.h"
#include "draw.h"

int	main(int argc, char **argv)
{
	t_config	config;

	if (!are_args_valid(argc, argv))
		return (1);
	if (!initialize_config(&config, argv))
		return (1);
	draw_fractal(&config);
	/* mlx_string_put(config.mlx.mlx_ptr, config.mlx.win_ptr, 50, 50, 0x00ffffff, "Hi there!"); */
	/* mlx_hook(config.mlx.win_ptr, int x_event, int x_mask, int (*funct)(), &config); */
	mlx_loop(config.mlx.mlx_ptr);
	return (0);
}
