/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 11:32:23 by pohl              #+#    #+#             */
/*   Updated: 2021/10/04 18:29:53 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "config.h"
#include "initialization.h"

int	main(int argc, char **argv)
{
	t_config	config;

	if (!initialize_config(&config, argc, argv))
		return (1);
	printf("Hi, this program will generate a keycodes.h file to put in pohl's f"
			"ractol project\nPlease select the window that appeared but make su"
			"re to see your terminal, and press the keys when prompted\n");
	prompt_for_key(&config);
	create_hooks(&config);
	mlx_loop(config.mlx.mlx_ptr);
	return (0);
}
