/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:26:55 by pohl              #+#    #+#             */
/*   Updated: 2021/09/28 16:29:58 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static void	handle_movement(int keycode, t_config *cfg)
{
	if (cfg->is_shift_pressed)
	{
		if (keycode == KC_RIGHT_ARR)
			cfg->wscreen.origin.x += cfg->wscreen.width / 4;
		else if (keycode == KC_LEFT_ARR)
			cfg->wscreen.origin.x -= cfg->wscreen.width / 4;
		else if (keycode == KC_UP_ARR)
			cfg->wscreen.origin.y += cfg->wscreen.width / 4;
		else if (keycode == KC_DOWN_ARR)
			cfg->wscreen.origin.y -= cfg->wscreen.width / 4;
	}
	else
	{
		if (keycode == KC_RIGHT_ARR)
			cfg->wscreen.origin.x += cfg->wscreen.width / 10;
		else if (keycode == KC_LEFT_ARR)
			cfg->wscreen.origin.x -= cfg->wscreen.width / 10;
		else if (keycode == KC_UP_ARR)
			cfg->wscreen.origin.y += cfg->wscreen.width / 10;
		else if (keycode == KC_DOWN_ARR)
			cfg->wscreen.origin.y -= cfg->wscreen.width / 10;
	}
}

static void	handle_julia_constant(int keycode, t_config *cfg)
{
	if (keycode == KC_W)
		cfg->algo.julia_constant += 0.01 * I;
	else if (keycode == KC_S)
		cfg->algo.julia_constant -= 0.01 * I;
	else if (keycode == KC_A)
		cfg->algo.julia_constant -= 0.01;
	else if (keycode == KC_D)
		cfg->algo.julia_constant += 0.01;
	else if (keycode == KC_R)
		cfg->algo.julia_constant = 0;
}

static void	handle_zooming(int keycode, t_config *cfg)
{
	if (keycode == KC_EQUAL)
	{
		if (cfg->is_shift_pressed)
			zoom_center(0.7, cfg);
		else
			zoom_center(0.92, cfg);
	}
	else if (keycode == KC_MINUS)
	{
		if (cfg->is_shift_pressed)
			zoom_center(1.3, cfg);
		else
			zoom_center(1.08, cfg);
	}
	else if (keycode == KC_0)
		set_zoom_value(0, cfg);
}

static void	handle_algorithm_selection(int keycode, t_config *cfg)
{
	if (keycode == KC_1)
		cfg->algo.type = MANDELBROT;
	else if (keycode == KC_2)
		cfg->algo.type = JULIA;
	else if (keycode == KC_3)
		cfg->algo.type = BURNING_SHIP;
	else if (keycode == KC_4)
		cfg->algo.type = BURNING_JULIA;
	else if (keycode == KC_5)
		cfg->algo.type = INVERSE_MANDELBROT;
	else if (keycode == KC_6)
		cfg->algo.type = GLYNN;
}
