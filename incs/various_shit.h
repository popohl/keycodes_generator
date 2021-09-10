/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various_shit.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:55:30 by pohl              #+#    #+#             */
/*   Updated: 2021/09/10 13:52:10 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIOUS_SHIT_H
# define VARIOUS_SHIT_H

# include <stdbool.h>
# include "main_structs.h"

# define ERROR -1

t_complex	get_coordinates(t_ivector2 screen_coord, t_ivector2 screen_size,
		t_world_screen *world_screen);
int	get_iteration_count(t_complex coordinates, t_algorithm *algo);
int	get_color_value(int r, int g, int b);

#endif
