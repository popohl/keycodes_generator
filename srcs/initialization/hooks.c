/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:12:55 by pohl              #+#    #+#             */
/*   Updated: 2021/10/04 20:42:45 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "mlx.h"
#include "libft.h"
#include "initialization.h"
#include "keys.h"

int	exit_program(void *param)
{
	t_config	*config;

	config = param;
	write(config->fd, "\n#endif\n", 8);
	close(config->fd);
	printf("\n---------------------------------------------------------------\n"
		"The file is now generated, thank you, you can enter this command to pu"
		"t it in the project:\nmv ./keycodes.h ../path/to/fractol/incs/linux_sp"
		"ecific/keycodes.h\n");
	exit(0);
	return (0);
}

void	prompt_for_key(t_config *config)
{
	static int	i = 0;

	if (i == sizeof(keys_infos) / MAX_SIZE)
		exit_program(config);
	printf("Please press the %s key on your keyboard\n", keys_infos[i]);
	i++;
}

int	key_press(int keycode, void *param)
{
	static int	i = 0;
	t_config	*config;
	char		*keycode_char;

	config = param;
	write(config->fd, "# define KC_", 12);
	write(config->fd, keys_infos[i], ft_strlen(keys_infos[i]));
	write(config->fd, " ", 1);
	keycode_char = ft_itoa(keycode);
	write(config->fd, keycode_char, ft_strlen(keycode_char));
	write(config->fd, "\n", 1);
	prompt_for_key(config);
	free(keycode_char);
	i++;
	return (0);
}

void	create_hooks(t_config *config)
{
	mlx_hook(config->mlx.win_ptr, 2, 1L << 0, key_press, config);
	mlx_hook(config->mlx.win_ptr, 17, 1L << 0, exit_program, NULL);
}
