/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulohl <pohl@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:04:59 by paulohl           #+#    #+#             */
/*   Updated: 2021/03/16 13:05:30 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

typedef struct s_opt
{
	char	*optarg;
	int		optind;
	int		optopt;
	int		opterr;
	int		optreset;
}	t_opt;

int		ft_getopt(t_opt *options, int argc, char *argv[], char *optstring);

#endif
