/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulohl <pohl@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:51:35 by paulohl           #+#    #+#             */
/*   Updated: 2021/09/28 16:12:55 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "config.h"
# include <stdbool.h>

/*
 ** bmp_creator.c
 */

int		create_img(int img_width, int img_height, int *img_data);

/*
** draw.c
*/

void	draw_fractal(t_config *config);
int		get_int_color_from_rgb(int r, int g, int b);
void	fill_img(t_config *config, t_image_info *img);

/*
** generate_screenshot.c
*/

bool	generate_screenshot(t_config *config);

/*
** hud.c
*/

void	draw_hud(t_config *config);
void	display_help(t_mlx_params *mlx, t_image_info *img);

/*
** color_functions.c
*/

int		hsv_to_rgb(double hue, double sat, double val);

#endif
