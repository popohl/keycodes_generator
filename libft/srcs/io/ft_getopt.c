/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulohl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 10:15:42 by paulohl           #+#    #+#             */
/*   Updated: 2021/03/31 12:30:03 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_getopt.h"
#include "libft.h"

char	*initialize(t_opt *options)
{
	options->optarg = 0;
	options->optind = 0;
	options->optopt = 0;
	options->optreset = 0;
	return ("");
}

int	get_arg(t_opt *opt, int argc, char *argv[], char **nextchar)
{
	opt->optarg = 0;
	if (++(opt->optind) >= argc)
		return (-1);
	*nextchar = argv[opt->optind];
	if ((*nextchar)[0] == '-' && (*nextchar)[1] == '-' && (*nextchar)[2] == 0)
	{
		opt->optind++;
		return (-1);
	}
	else if ((*nextchar)[0] != '-'
		|| ((*nextchar)[0] == '-' && (*nextchar)[1] == 0))
		return (-1);
	(*nextchar)++;
	return (0);
}

int	error(char *prog_name, char c, t_opt *opt, int mode)
{
	int		n;

	n = 0;
	while (prog_name[n])
		n++;
	if (opt->opterr)
	{
		write(2, prog_name, n);
		if (mode == 1)
			write(2, ": illegal option -- ", 20);
		else
			write(2, ": option requires an argument -- ", 33);
		write(2, &c, 1);
		write(2, "\n", 1);
	}
	opt->optopt = c;
	return ('?');
}

int	read_string(int argc, char *argv[], t_opt *opt, char **nextchar)
{
	int		i;

	i = 0;
	if (**nextchar)
	{
		opt->optarg = *nextchar;
		while ((*nextchar)[i])
			i++;
		*nextchar += i;
		return (0);
	}
	else if (++opt->optind >= argc)
		return (-1);
	else
	{
		opt->optarg = argv[opt->optind];
		return (0);
	}
}

int	ft_getopt(t_opt *opt, int argc, char *argv[], char *optstring)
{
	static char	*nextchar = (char *) - 1;
	int			i;

	if (nextchar == (char *) - 1 || opt->optreset == 1)
		nextchar = initialize(opt);
	if ((*nextchar == 0) && get_arg(opt, argc, argv, &nextchar))
		return (-1);
	i = 0;
	while (optstring[i] && optstring[i] != *nextchar)
		i++;
	if (optstring[i] != *nextchar)
		i = -1;
	nextchar++;
	opt->optopt = i;
	if (opt->optopt == -1)
		return (error(argv[0], *(nextchar - 1), opt, 1));
	else
	{
		if (optstring[opt->optopt + 1] == ':'
			&& read_string(argc, argv, opt, &nextchar))
			return (error(argv[0], *(nextchar - 1), opt, 2));
		return (optstring[opt->optopt]);
	}
	return (0);
}
