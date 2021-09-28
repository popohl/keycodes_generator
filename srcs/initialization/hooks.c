/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:12:55 by pohl              #+#    #+#             */
/*   Updated: 2021/09/28 16:46:50 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "draw.h"
#include "keycodes.h"
#include "algorithms.h"
#include "initialization.h"

int	close(void)
{
	exit(0);
	return (0);
}

int	mouse_press(int button, int x, int y, void *param)
{
	t_config	*config;

	config = param;
	if (button == 4)
	{
		zoom_mouse(0.92, x, y, config);
		draw_fractal(config);
	}
	else if (button == 5)
	{
		zoom_mouse(1.08, x, y, config);
		draw_fractal(config);
	}
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_config	*cfg;

	cfg = param;
	if (keycode == KC_LEFT_SHIFT || keycode == KC_RIGHT_SHIFT)
		cfg->is_shift_pressed = false;
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_config	*cfg;

	cfg = param;
	handle_movement(keycode, cfg);
	handle_zooming(keycode, cfg);
	handle_julia_constant(keycode, cfg);
	handle_algorithm_selection(keycode, cfg);
	if (keycode == KC_POINT)
		cfg->algo.max_iteration += 50;
	if (keycode == KC_COMMA && cfg->algo.max_iteration > 50)
		cfg->algo.max_iteration -= 50;
	if (keycode == KC_Q || keycode == KC_ESCAPE)
		close();
	if (keycode == KC_P)
		generate_screenshot(cfg);
	if (keycode == KC_H)
		cfg->display_hud = !cfg->display_hud;
	if (keycode == KC_LEFT_SHIFT || keycode == KC_RIGHT_SHIFT)
		cfg->is_shift_pressed = true;
	draw_fractal(cfg);
	if (keycode == KC_SLASH)
		display_help(&cfg->mlx, &cfg->img);
	return (0);
}

void	create_hooks(t_config *config)
{
	mlx_hook(config->mlx.win_ptr, 2, 1L << 0, key_press, config);
	mlx_hook(config->mlx.win_ptr, 3, 1L << 1, key_release, config);
	mlx_hook(config->mlx.win_ptr, 4, 1L << 2, mouse_press, config);
	mlx_hook(config->mlx.win_ptr, 17, 1L << 0, close, NULL);
}
