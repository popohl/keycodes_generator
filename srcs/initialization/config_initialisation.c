/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_initialisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulohl <pohl@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:00:18 by paulohl           #+#    #+#             */
/*   Updated: 2021/09/22 20:04:21 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "mlx.h"
#include "libft.h"
#include "config.h"
#include "algorithms.h"
#include "initialization.h"

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

static bool	initialize_hud(t_mlx_params *mlx, t_image_info *hud)
{
	int i;

	hud->size.x = 350;
	hud->size.y = 85;
	hud->img_ptr = mlx_new_image(mlx->mlx_ptr, hud->size.x, hud->size.y);
	if (!hud->img_ptr)
		return (false);
	hud->data = (int *)mlx_get_data_addr(hud->img_ptr, &hud->img_depth,
			&hud->size_line, &hud->endian);
	if (!hud->data)
		return (false);
	hud->size_line /= 4;
	i = 0;
	while (i < hud->size.x * hud->size.y)
	{
		hud->data[i] = 0;
		i++;
	}
	return (true);
}

static bool get_algo_type(char *type, int *type_to_set)
{
	if (!ft_strcmp("mandelbrot", type))
		*type_to_set = MANDELBROT;
	else if (!ft_strcmp("julia", type))
		*type_to_set = JULIA;
	else if (!ft_strcmp("burning_ship", type))
		*type_to_set = BURNING_SHIP;
	else if (!ft_strcmp("burning_julia", type))
		*type_to_set = BURNING_JULIA;
	else if (!ft_strcmp("inverse_mandelbrot", type))
		*type_to_set = INVERSE_MANDELBROT;
	else
		return (false);
	return (true);
}

double complex	set_julia_constant(char **argv)
{
	double			tmp_real;
	double			tmp_imag;
	double complex	result;

	tmp_real = ft_atod(argv[2]);
	tmp_imag = ft_atod(argv[3]);
	result = tmp_real + I * tmp_imag;
	return (result);
}

bool	initialize_config(t_config *config, int argc, char **argv)
{
	if (argc < 2)
		return (error(ARG_COUNT));
	if (!get_algo_type(argv[1], &config->algo.type))
		return (error(ALGO_TYPE));
	config->algo.julia_constant = 0.36 + 0.07 * I;
	if (argc == 4)
		config->algo.julia_constant = set_julia_constant(argv);
	else if (argc != 2)
		return (error(ARG_COUNT));
	config->img.size.x = 1280;
	config->img.size.y = 720;
	if (!initialize_mlx_stuff(&config->mlx, &config->img))
		return (false);
	if (!initialize_hud(&config->mlx, &config->hud))
		return (false);
	config->algo.max_iteration = 100;
	config->wscreen.origin.x = 0;
	config->wscreen.origin.y = 0;
	set_wscreen_width(config, 4.0);
	config->is_shift_pressed = false;
	config->display_hud = true;
	return (true);
}
