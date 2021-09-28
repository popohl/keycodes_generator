/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:15:37 by pohl              #+#    #+#             */
/*   Updated: 2021/09/28 13:57:52 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

/*
** write_bmfh writes the bmp file header in the bmp file
** this header gives info on the file itself
*/

static bool	write_bmfh(int fd, int img_width, int img_height)
{
	int		temp;

	if (write(fd, "BM", 2) == -1)
		return (false);
	temp = 54 + img_width * img_height * 4;
	if (write(fd, &temp, 4) == -1)
		return (false);
	temp = 0;
	if (write(fd, &temp, 4) == -1)
		return (false);
	temp = 54;
	if (write(fd, &temp, 4) == -1)
		return (false);
	return (true);
}

/*
** write_bmih writes the bmp image header in the bmp file after the bmfh
** this header gives info on the image
*/

static bool	write_bmih(int fd, int img_width, int img_height)
{
	int		i;
	int		temp;

	temp = 40;
	if (write(fd, &temp, 4) == -1)
		return (false);
	if (write(fd, &img_width, 4) == -1)
		return (false);
	if (write(fd, &img_height, 4) == -1)
		return (false);
	if (write(fd, "\1\0", 2) == -1)
		return (false);
	temp = 32;
	if (write(fd, &temp, 2) == -1)
		return (false);
	temp = 0;
	i = 0;
	while (i < 6)
	{
		if (write(fd, &temp, 4) == -1)
			return (false);
		i++;
	}
	return (true);
}

/*
** write_img writes the image from the screen into the file line by line,
** bottom to top, because images are stored upside down in the bmp format
*/

static bool	write_img(int fd, int *img_data, int img_width, int img_height)
{
	int		i;

	i = img_width * img_height;
	while (i > 0)
	{
		i -= img_width;
		if (write(fd, img_data + i, img_width * 4) == -1)
			return (false);
	}
	return (true);
}

/*
** create_pathname creates a name for the image using a static int counting the
** screenshot number
*/

static char	*create_pathname(int screenshot_count)
{
	char		*path;
	int			char_count;
	int			i;

	if (screenshot_count < 10000)
	{
		path = ft_strdup("screenshots/sc-0000.bmp");
		if (!path)
			return (NULL);
	}
	else
		return (NULL);
	char_count = ft_intlen(screenshot_count);
	i = 0;
	while (i < char_count)
	{
		path[18 - i] = screenshot_count % 10 + '0';
		screenshot_count /= 10;
		i++;
	}
	return (path);
}

/*
** create_img will create a file with a chmod of 755 and write the image given
** in parameter in it.
*/

bool	create_img(int img_width, int img_height, int *img_data)
{
	int			fd;
	static int	screenshot_count = 0;
	char		*path;

	path = create_pathname(++screenshot_count);
	if (!path)
		return (false);
	fd = open(path, O_CREAT | O_WRONLY, S_IRWXU
				| S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	if (!write_bmfh(fd, img_width, img_height))
		return (false);
	if (!write_bmih(fd, img_width, img_height))
		return (false);
	if (!write_img(fd, img_data, img_width, img_height))
		return (false);
	if (path)
		free(path);
	close(fd);
	return (true);
}
