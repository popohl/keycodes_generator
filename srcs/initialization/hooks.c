/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:12:55 by pohl              #+#    #+#             */
/*   Updated: 2021/09/16 15:55:24 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "draw.h"
#include "keycodes.h"
#include "algorithms.h"

int close(void *param)
{
	t_config	*config = param;

	mlx_destroy_image(config->mlx.mlx_ptr, config->mlx.win_ptr); 
	/* mlx_destroy_window(config->mlx.mlx_ptr, config->mlx.win_ptr); */ 
	exit(0);
	return (0);
}

int	mouse_press(int button, int x, int y, void *param)
{
	t_config	*config;

	config = param;
	x = 0;
	y = 0;
	if (button == 4)
	{
		set_wscreen_width(config, config->wscreen.width /= 1.1);
		draw_fractal(config);
	}
	if (button == 5)
	{
		set_wscreen_width(config, config->wscreen.width *= 1.1);
		draw_fractal(config);
	}
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	t_config		*config;
	t_ivect2		screen_coord;
	double complex	world_coordinates;
	unsigned int	iterations;
	int				red_value;

	config = (t_config *)param;
	screen_coord.x = x;
	screen_coord.y = y;
	world_coordinates = get_coordinates(screen_coord, config->img.size,
			&config->wscreen);
	iterations = get_iteration_count(world_coordinates, &config->algo);
	red_value = ((double)iterations / config->algo.max_iteration) * 255;
	printf("(%d, %d) => (%f, %f) = %d its / %d max; red: %d\n", x, y, creal(world_coordinates),
			cimag(world_coordinates), iterations, config->algo.max_iteration, red_value);
	return (0);
}

void	set_wscreen_width_on_key(int keycode, t_config *cfg)
{
	if (keycode == KC_EQUAL)
		set_wscreen_width(cfg, cfg->wscreen.width /= 1.08);
	if (keycode == KC_MINUS)
		set_wscreen_width(cfg, cfg->wscreen.width *= 1.08);
	if (keycode == KC_0)
		set_wscreen_width(cfg, 4.0);
}

int	key_press(int keycode, void *param)
{
	t_config	*cfg;

	cfg = param;
	if (keycode == KC_RIGHT_ARR)
		cfg->wscreen.origin.x += cfg->wscreen.width / 10;
	if (keycode == KC_LEFT_ARR)
		cfg->wscreen.origin.x -= cfg->wscreen.width / 10;
	if (keycode == KC_UP_ARR)
		cfg->wscreen.origin.y += cfg->wscreen.width / 10;
	if (keycode == KC_DOWN_ARR)
		cfg->wscreen.origin.y -= cfg->wscreen.width / 10;
	set_wscreen_width_on_key(keycode, cfg);
	if (keycode == KC_W)
		cfg->algo.julia_constant += 0.01 * I;
	if (keycode == KC_S)
		cfg->algo.julia_constant -= 0.01 * I;
	if (keycode == KC_A)
		cfg->algo.julia_constant -= 0.01;
	if (keycode == KC_D)
		cfg->algo.julia_constant += 0.01;
	if (keycode == KC_POINT)
		cfg->algo.max_iteration += 50;
	if (keycode == KC_COMMA)
		cfg->algo.max_iteration -= 50;
	if (keycode == KC_1)
		cfg->algo.type = MANDELBROT;
	if (keycode == KC_2)
		cfg->algo.type = JULIA;
	if (keycode == KC_3)
		cfg->algo.type = BURNING_SHIP;
	if (keycode == KC_4)
		cfg->algo.type = INVERSE_MANDELBROT;
	if (keycode == KC_Q || keycode == KC_ESCAPE)
		close(cfg);
	draw_fractal(cfg);
	if (keycode == KC_J)
		printf("%f + %f * i\n", creal(cfg->algo.julia_constant), cimag(cfg->algo.julia_constant));
	return (0);
}

void	create_hooks(t_config *config)
{
	mlx_hook(config->mlx.win_ptr, 2, 1L<<0, key_press, config);
	mlx_hook(config->mlx.win_ptr, 4, 1L<<2, mouse_press, config);
	mlx_hook(config->mlx.win_ptr, 17, 1L<<0, close, config);
	/* mlx_hook(config.mlx.win_ptr, 6, 1L<<13, mouse_move, &config); */
}
