/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:03:23 by pohl              #+#    #+#             */
/*   Updated: 2021/09/21 15:45:44 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_STRUCTS_H
# define MAIN_STRUCTS_H

#include "debug.h"

# include "useful_structs.h"
# include <complex.h>

# define ESCAPE_VALUE 2

enum	e_algorithm_type
{
	MANDELBROT = 0,
	JULIA,
	BURNING_SHIP,
	BURNING_JULIA,
	INVERSE_MANDELBROT,
};

typedef struct	s_image_info
{
	void		*img_ptr;
	int			*data;
	t_ivect2	size;
	int			size_line;
	int			endian;
	int			img_depth;
}	t_image_info;

typedef struct	s_world_screen
{
	t_dvect2	origin;
	double		width;
	double		height;
}	t_world_screen;

typedef	struct s_mlx_params
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_params;

typedef struct s_algorithm
{
	double complex	julia_constant;
	int				max_iteration;
	int				type;
}	t_algorithm;

typedef struct s_config
{
	t_mlx_params	mlx;
	t_image_info	img;
	t_algorithm		algo;
	t_world_screen	wscreen;
}	t_config;

#endif
