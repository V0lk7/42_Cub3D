/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:44:26 by vviovi            #+#    #+#             */
/*   Updated: 2023/06/19 08:53:07 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

void	draw_texture_line(t_data *data, int *line_texture, int x, int length)
{
	int		i;
	int		y;
	int		end;
	int32_t	color;

	y = HEIGHT / 2 - length / 2;
	end = HEIGHT / 2 + length / 2;
	if (y < 0)
		y = 0;
	if (end > HEIGHT)
		end = HEIGHT - 1;
	while (y <= end)
	{
		i = (y * 2 - HEIGHT + length) * (64 / 2) / length;
		i *= 4;
		color = color_pixel(line_texture[i], line_texture[i + 1],
				line_texture[i + 2], line_texture[i + 3]);
		mlx_put_pixel(data->img[WALL], x, y, color);
		y++;
	}
	free(line_texture);
	line_texture = NULL;
}

int	*get_line_texture(int pos, mlx_texture_t texture)
{
	int				*line;
	unsigned int	i;
	unsigned int	j;

	line = malloc(sizeof(int) * (texture.width + 1) * texture.bytes_per_pixel);
	if (line == NULL)
		return (NULL);
	i = 0;
	pos = pos * texture.bytes_per_pixel;
	while (i < texture.width * texture.bytes_per_pixel)
	{
		j = 0;
		while (j < texture.bytes_per_pixel)
		{
			line[i + j] = texture.pixels[pos + j];
			j++;
		}
		i += texture.bytes_per_pixel;
		pos += texture.width * texture.bytes_per_pixel;
	}
	return (line);
}

float	scale_calculate(float dist_foc, float dist, float size_texture)
{
	float	scale;

	if (dist == 0.0f)
		dist = 1.0f;
	scale = size_texture / dist * dist_foc;
	return (scale);
}
