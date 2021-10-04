/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:03:23 by pohl              #+#    #+#             */
/*   Updated: 2021/10/04 20:17:06 by pohl             ###   ########.fr       */
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

#endif
