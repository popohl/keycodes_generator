/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_initialisation.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulohl <pohl@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:32:36 by paulohl           #+#    #+#             */
/*   Updated: 2021/09/14 14:29:19 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_INITIALISATION_H
# define CONFIG_INITIALISATION_H

bool	initialize_config(t_config *config, char **argv);
void	set_wscreen_width(t_config *config, double width);

#endif
