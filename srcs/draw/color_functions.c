/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:17:57 by pohl              #+#    #+#             */
/*   Updated: 2021/09/28 16:58:49 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "config.h"
#include "draw.h"

int	get_color_value(int r, int g, int b)
{
	int		color;

	color = 0;
	color = color | (r << 16);
	color = color | (g << 8);
	color = color | b;
	return (color);
}

int	get_color_value_double(double r, double g, double b)
{
	return (get_color_value(floor(r * 255), floor(g * 255), floor(b * 255)));
}

int	hsv_to_rgb(double hue, double sat, double val)
{
	double	chroma;
	double	min;
	double	tmp;

	chroma = 0.0;
	min = 0.0;
	tmp = 0.0;
	chroma = val * sat;
	tmp = chroma * (1.0 - fabs(fmod(hue / 60.0, 2) - 1.0));
	min = val - chroma;
	if (hue >= 0.0 && hue < 60.0)
		return (get_color_value_double(chroma + min, tmp + min, min));
	else if (hue >= 60.0 && hue < 120.0)
		return (get_color_value_double(tmp + min, chroma + min, min));
	else if (hue >= 120.0 && hue < 180.0)
		return (get_color_value_double(min, chroma + min, tmp + min));
	else if (hue >= 180.0 && hue < 240.0)
		return (get_color_value_double(min, tmp + min, chroma + min));
	else if (hue >= 240.0 && hue < 300.0)
		return (get_color_value_double(tmp + min, min, chroma + min));
	else if (hue >= 300.0 && hue < 360.0)
		return (get_color_value_double(chroma + min, min, tmp + min));
	else
		return (get_color_value_double(min, min, min));
}
