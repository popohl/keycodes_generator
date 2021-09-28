/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:53:53 by pohl              #+#    #+#             */
/*   Updated: 2021/09/28 16:51:26 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "config.h"
#include "draw.h"

static char	*get_fractal_type(char *str, int type)
{
	ft_strcpy(str, "Fractal type: ");
	if (type == MANDELBROT)
		ft_strcpy(str + 14, "mandelbrot");
	if (type == JULIA)
		ft_strcpy(str + 14, "julia");
	if (type == BURNING_SHIP)
		ft_strcpy(str + 14, "burning ship");
	if (type == BURNING_JULIA)
		ft_strcpy(str + 14, "burning julia");
	if (type == INVERSE_MANDELBROT)
		ft_strcpy(str + 14, "inverse mandelbrot");
	return (str);
}

static char	*get_fractal_zoom(char *str, double wscreen_width)
{
	long	zoom_level_nbr;
	char	*zoom_level_str;

	ft_strcpy(str, "Zoom level: x");
	zoom_level_nbr = (long)(4 / wscreen_width);
	if (zoom_level_nbr < 10000)
	{
		zoom_level_str = ft_itoa(zoom_level_nbr);
		ft_strcpy(str + 13, zoom_level_str);
	}
	else
	{
		ft_strcpy(str + 13, "10^");
		zoom_level_str = ft_itoa(ft_longlen(zoom_level_nbr));
		ft_strcpy(str + 16, zoom_level_str);
	}
	free(zoom_level_str);
	return (str);
}

void	draw_hud(t_config *config)
{
	int		color;
	char	*str;

	color = get_int_color_from_rgb(255, 255, 255);
	str = (char *)malloc(100 * sizeof(char));
	if (!str)
		return ;
	mlx_put_image_to_window(config->mlx.mlx_ptr, config->mlx.win_ptr,
		config->hud.img_ptr, 5, 5);
	mlx_string_put(config->mlx.mlx_ptr, config->mlx.win_ptr, 7, 25, color,
		get_fractal_type(str, config->algo.type));
	mlx_string_put(config->mlx.mlx_ptr, config->mlx.win_ptr, 7, 45, color,
		get_fractal_zoom(str, config->wscreen.width));
	mlx_string_put(config->mlx.mlx_ptr, config->mlx.win_ptr, 7, 65, color,
		"Show commands: ?");
	free(str);
}
