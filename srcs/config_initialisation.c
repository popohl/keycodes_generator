/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_initialisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulohl <pohl@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:00:18 by paulohl           #+#    #+#             */
/*   Updated: 2021/09/10 19:09:29 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "main_structs.h"
#include "various_shit.h"
#include "mlx.h"

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
	config->img.size.x = 1360;
	config->img.size.y = 800;
	if (!initialize_mlx_stuff(&config->mlx, &config->img))
		return (false);
	config->algo.type = MANDELBROT;
	config->algo.escape_value = 2.0;
	config->algo.max_iteration = 100;
	config->wscreen.origin.r = 0;
	config->wscreen.origin.i = 0;
	config->wscreen.width = config->algo.escape_value * 2;
	config->wscreen.height = config->wscreen.width *
		((double)config->img.size.y/ config->img.size.x);
	argv = NULL;
	return (true);
}
