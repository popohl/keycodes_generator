/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:50:10 by pohl              #+#    #+#             */
/*   Updated: 2021/09/28 17:50:56 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include "config.h"
#include "initialization.h"

bool	error(int error)
{
	if (error == ARG_COUNT)
		printf("Wrong number of arguments.\n");
	else if (error == ALGO_TYPE)
		printf("Algorithm type does not exist.\n");
	else
		printf("Unknown error.\n");
	printf("Usage: ./fractol [algorithm] {julia coordinates (optional)}\n"
		"algorithms: mandelbrot, julia, burning_ship, burning_julia, "
		"inverse_mandelbrot\n"
		"julia coordinates: the coordinates on the complex plane for the or"
		"igin point of the fractal\n");
	return (false);
}
