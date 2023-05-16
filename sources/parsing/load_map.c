/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:15:52 by vviovi            #+#    #+#             */
/*   Updated: 2023/05/16 09:35:59 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/type.h"
#include "map_verif.c"
#include "utils_map.c"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	load_textures_info(int file_fd, t_data *data)
{
	if (get_texture_info(file_fd, "NO", data))
		return (0);
	if (get_texture_info(file_fd, "SO", data))
		return (0);
	if (get_texture_info(file_fd, "WE", data))
		return (0);
	if (get_texture_info(file_fd, "EA", data))
		return (0);
	return (1);
}

int	load_colors(int file_fd, t_data *data)
{
	if (get_color_info(file_fd, "F", data))
		return (0);
	if (get_color_info(file_fd, "C", data))
		return (0);
}

int	load_map(int file_fd, t_data *data);

int	load_file(char **argv, t_data *data)
{
	int		fd;

	if (!valid_extension(argv[1], ".cub"))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		print_error_map(404);
		return (0);
	}
	if (!load_textures_info(fd, data)
			|| !load_colors(fd, data)
			|| !load_map(fd, data))
	{
		close(fd);
		return (0);
	}
	return (1);
}
