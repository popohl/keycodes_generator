/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_initialisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulohl <pohl@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:00:18 by paulohl           #+#    #+#             */
/*   Updated: 2021/10/04 20:33:34 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include "mlx.h"
#include "libft.h"
#include "config.h"

static bool	initialize_mlx_stuff(t_mlx_params *mlx, t_ivect2 screen_size)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (false);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, screen_size.x, screen_size.y,
			"useless");
	if (!mlx->win_ptr)
		return (false);
	return (true);
}

bool	initialize_config(t_config *config)
{
	config->screen_size.x = 100;
	config->screen_size.y = 100;
	config->fd = open("./keycodes.h", O_WRONLY | O_CREAT, 00755);
	write(config->fd, "#ifndef KEYCODES_H\n# define KEYCODES_H\n\n", 40);
	if (!initialize_mlx_stuff(&config->mlx, config->screen_size))
		return (false);
	return (true);
}
