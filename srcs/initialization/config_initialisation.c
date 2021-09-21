/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_initialisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulohl <pohl@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:00:18 by paulohl           #+#    #+#             */
/*   Updated: 2021/09/16 15:30:22 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "mlx.h"
#include "config.h"
#include "algorithms.h"

static bool	initialize_mlx_stuff(t_mlx_params *mlx, t_image_info *img)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (false);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, img->size.x, img->size.y,
			"Fractol");
	if (!mlx->win_ptr)
		return (false);
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, img->size.x, img->size.y);
	if (!img->img_ptr)
		return (false);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->img_depth,
			&img->size_line, &img->endian);
	if (!img->data)
		return (false);
	img->size_line /= 4;
	return (true);
}

bool	initialize_config(t_config *config, char **argv)
{
	config->img.size.x = 1280;
	config->img.size.y = 720;
	if (!initialize_mlx_stuff(&config->mlx, &config->img))
		return (false);
	config->algo.type = MANDELBROT;
	config->algo.max_iteration = 100;
	config->algo.julia_constant = 0.0;
	config->wscreen.origin.x = 0;
	config->wscreen.origin.y = 0;
	set_wscreen_width(config, 4.0);
	argv = NULL;
	return (true);
}
