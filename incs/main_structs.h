/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:03:23 by pohl              #+#    #+#             */
/*   Updated: 2021/09/10 11:58:31 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_STRUCTS_H
# define MAIN_STRUCTS_H

# include "useful_structs.h"

typedef struct	s_image_info
{
	void		*img_ptr;
	int			*data;
	t_ivector2	size;
	int			size_line;
	int			endian;
	int			img_depth;
}	t_image_info;

typedef struct	s_world_screen
{
	t_complex	origin;
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
	double	escape_value;
	double	max_iterations;
}	t_algorithm;

typedef struct s_config
{
	t_mlx_params	mlx;
	t_image_info	img;
	t_algorithm		algo;
	t_world_screen	vscreen;
}	t_config;

#endif
