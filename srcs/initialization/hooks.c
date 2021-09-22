/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:12:55 by pohl              #+#    #+#             */
/*   Updated: 2021/09/22 17:30:58 by pohl             ###   ########.fr       */
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
	if (button == 4)
	{
		zoom_mouse(0.92, x, y, config);
		draw_fractal(config);
	}
	if (button == 5)
	{
		zoom_mouse(1.08, x, y, config);
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

void	handle_zooming(int keycode, t_config *cfg)
{
	if (keycode == KC_EQUAL)
	{
		if (cfg->is_shift_pressed)
			zoom_center(0.7, cfg);
		else
			zoom_center(0.92, cfg);
	}
	if (keycode == KC_MINUS)
	{
		if (cfg->is_shift_pressed)
			zoom_center(1.3, cfg);
		else
			zoom_center(1.08, cfg);
	}
	if (keycode == KC_0)
		set_zoom_value(0, cfg);
	if (keycode == KC_9)
		set_zoom_value(7, cfg);
}

int key_release(int keycode, void *param)
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
	if (keycode == KC_RIGHT_ARR)
	{
		if (cfg->is_shift_pressed)
			cfg->wscreen.origin.x += cfg->wscreen.width / 4;
		else
			cfg->wscreen.origin.x += cfg->wscreen.width / 10;
	}
	if (keycode == KC_LEFT_ARR)
	{
		if (cfg->is_shift_pressed)
			cfg->wscreen.origin.x -= cfg->wscreen.width / 4;
		else
			cfg->wscreen.origin.x -= cfg->wscreen.width / 10;
	}
	if (keycode == KC_UP_ARR)
	{
		if (cfg->is_shift_pressed)
			cfg->wscreen.origin.y += cfg->wscreen.width / 4;
		else
			cfg->wscreen.origin.y += cfg->wscreen.width / 10;
	}
	if (keycode == KC_DOWN_ARR)
	{
		if (cfg->is_shift_pressed)
			cfg->wscreen.origin.y -= cfg->wscreen.width / 4;
		else
			cfg->wscreen.origin.y -= cfg->wscreen.width / 10;
	}
	handle_zooming(keycode, cfg);
	if (keycode == KC_W)
		cfg->algo.julia_constant += 0.01 * I;
	if (keycode == KC_S)
		cfg->algo.julia_constant -= 0.01 * I;
	if (keycode == KC_A)
		cfg->algo.julia_constant -= 0.01;
	if (keycode == KC_D)
		cfg->algo.julia_constant += 0.01;
	if (keycode == KC_R)
		cfg->algo.julia_constant = 0;
	if (keycode == KC_POINT)
		cfg->algo.max_iteration += 50;
	if (keycode == KC_COMMA && cfg->algo.max_iteration > 50)
		cfg->algo.max_iteration -= 50;
	if (keycode == KC_1)
		cfg->algo.type = MANDELBROT;
	if (keycode == KC_2)
		cfg->algo.type = JULIA;
	if (keycode == KC_3)
		cfg->algo.type = BURNING_SHIP;
	if (keycode == KC_4)
		cfg->algo.type = BURNING_JULIA;
	if (keycode == KC_5)
		cfg->algo.type = INVERSE_MANDELBROT;
	if (keycode == KC_Q || keycode == KC_ESCAPE)
		close(cfg);
	if (keycode == KC_P)
		generate_screenshot(cfg);
	if (keycode == KC_LEFT_SHIFT || keycode == KC_RIGHT_SHIFT)
		cfg->is_shift_pressed = true;
	draw_fractal(cfg);
	if (keycode == KC_J)
		printf("%f + %f * i\n", creal(cfg->algo.julia_constant), cimag(cfg->algo.julia_constant));
	return (0);
}

void	create_hooks(t_config *config)
{
	mlx_hook(config->mlx.win_ptr, 2, 1L<<0, key_press, config);
	mlx_hook(config->mlx.win_ptr, 3, 1L<<1, key_release, config);
	mlx_hook(config->mlx.win_ptr, 4, 1L<<2, mouse_press, config);
	mlx_hook(config->mlx.win_ptr, 17, 1L<<0, close, config);
	/* mlx_hook(config->mlx.win_ptr, 6, 1L<<13, mouse_move, config); */
}
