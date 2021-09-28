/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:45:17 by pohl              #+#    #+#             */
/*   Updated: 2021/09/28 13:39:20 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"

#define HELP_TOP 100
#define HELP_SIDES 350
#define HELP_BOTTOM 150
#define TEXT_OFFSET 200

static void	draw_help_bg(t_mlx_params *mlx, t_image_info *img)
{
	int	i;
	int	y;
	int	color;

	color = 0;
	i = HELP_SIDES;
	while (i < img->size.x - HELP_SIDES)
	{
		y = HELP_TOP;
		while (y < img->size.y - HELP_BOTTOM)
		{
			img->data[y * img->size_line + i] = color;
			y++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
}

static void	write_help_line(t_mlx_params *mlx, int x, char *str)
{
	static int	y = HELP_TOP + 25;

	if (str == NULL)
		y = HELP_TOP + 25;
	else
	{
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xffffffff, str);
		y += 30;
	}
}

void	display_help(t_mlx_params *mlx, t_image_info *img)
{
	int	x_pos;

	draw_help_bg(mlx, img);
	x_pos = img->size.x / 2 - TEXT_OFFSET;
	write_help_line(mlx, x_pos, "move view: arrows");
	write_help_line(mlx, x_pos, "move view faster: Shift + arrows");
	write_help_line(mlx, x_pos, "zoom: '-' and '='");
	write_help_line(mlx, x_pos, "zoom faster: Shift + '-' and '='");
	write_help_line(mlx, x_pos, "reset zoom: '0'");
	write_help_line(mlx, x_pos, "zoom focusing on cursor: Scroll Wheel");
	write_help_line(mlx, x_pos, "increase/decrease iterations: '<' and '>'");
	write_help_line(mlx, x_pos, "select algorithm: '1', '2', '3', '4', '5'");
	write_help_line(mlx, x_pos, "move Julia's constant: WASD");
	write_help_line(mlx, x_pos, "reset Julia's constant: R");
	write_help_line(mlx, x_pos, "take a screenshot: 'P'");
	write_help_line(mlx, x_pos, "display/hide hud: 'H'");
	write_help_line(mlx, x_pos, "display help: '?'");
	write_help_line(mlx, x_pos, "quit: 'Q' or Esc");
	write_help_line(mlx, x_pos, NULL);
}
