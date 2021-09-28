/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_screenshot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 23:12:16 by pohl              #+#    #+#             */
/*   Updated: 2021/09/28 13:58:59 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "config.h"
#include "draw.h"

bool	generate_screenshot(t_config *config)
{
	t_image_info	screenshot;

	screenshot.img_ptr = NULL;
	screenshot.size.x = 3840;
	screenshot.size.y = 2160;
	screenshot.size_line = 3840;
	screenshot.endian = config->img.endian;
	screenshot.img_depth = config->img.img_depth;
	screenshot.data = malloc(screenshot.size.x * screenshot.size.y *
		sizeof(int));
	if (!screenshot.data)
		return (false);
	fill_img(config, &screenshot);
	create_img(screenshot.size.x, screenshot.size.y, screenshot.data);
	free(screenshot.data);
	return (true);
}
