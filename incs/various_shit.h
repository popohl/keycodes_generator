/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various_shit.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:55:30 by pohl              #+#    #+#             */
/*   Updated: 2021/08/24 19:33:41 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIOUS_SHIT_H
# define VARIOUS_SHIT_H

# include <stdbool.h>
# include "main_structs.h"

# define ERROR -1

t_complex	get_coordinates(int x, int y, t_ivector2 screen_size, double escape_value);
int	get_iteration_count(t_complex coordinates, double escape_value, int max_iterations);
int	get_color_value(int r, int g, int b);
int hsv_to_rgb(double hue, double sat, double val);

#endif
