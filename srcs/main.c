/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 11:32:23 by pohl              #+#    #+#             */
/*   Updated: 2021/09/16 14:02:46 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "draw.h"
#include "initialization.h"

int	main(int argc, char **argv)
{
	t_config	config;

	if (!are_args_valid(argc, argv))
		return (1);
	if (!initialize_config(&config, argv))
		return (1);
	draw_fractal(&config);
	create_hooks(&config);
	mlx_loop(config.mlx.mlx_ptr);
	return (0);
}

/* void name_of_function() __attribute__((destructor)); */

/* void name_of_function() */
/* { */
/*     system("leaks fractol"); */
/* } */
