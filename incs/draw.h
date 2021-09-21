/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulohl <pohl@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:51:35 by paulohl           #+#    #+#             */
/*   Updated: 2021/09/16 14:15:17 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "config.h"

/*
** draw.c
*/

void	draw_fractal(t_config *config);
int	get_color_value(int r, int g, int b);

#endif
