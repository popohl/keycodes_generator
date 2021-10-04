/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:03:23 by pohl              #+#    #+#             */
/*   Updated: 2021/10/04 18:46:30 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "useful_structs.h"
# include <complex.h>
# include <stdbool.h>

typedef struct s_mlx_params
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_params;

typedef struct s_config
{
	t_mlx_params	mlx;
	t_ivect2		screen_size;
	int				fd;
}	t_config;

# define MAX_SIZE 12

const char keys[][MAX_SIZE] =
{
	"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
	"P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3",
	"4", "5", "6", "7", "8", "9", "EQUAL", "MINUS", "COMMA",
	"POINT", "LEFT_ARR", "RIGHT_ARR", "UP_ARR", "DOWN_ARR", "LEFT_SHIFT",
	"RIGHT_SHIFT", "LEFT_CTRL", "RIGHT_CTRL", "SPACE", "ESCAPE", "SLASH",
};

#endif
