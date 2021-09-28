/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:43:39 by pohl              #+#    #+#             */
/*   Updated: 2021/09/28 16:45:31 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

# include <stdbool.h>

enum e_error_codes
{
	ARG_COUNT = 0,
	ALGO_TYPE,
};

/*
** hooks.c
*/

void	create_hooks(t_config *config);

/*
** checkers.c
*/

bool	initialize_config(t_config *config, int argc, char **argv);

/*
** error.c
*/

bool	error(int error);

/*
** error.c
*/

void	handle_movement(int keycode, t_config *cfg);
void	handle_julia_constant(int keycode, t_config *cfg);
void	handle_zooming(int keycode, t_config *cfg);
void	handle_algorithm_selection(int keycode, t_config *cfg);

#endif
