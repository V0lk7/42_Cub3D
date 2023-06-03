/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:30:26 by jduval            #+#    #+#             */
/*   Updated: 2023/06/03 18:24:06 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "cub3d.h"
#include "libft.h"

static int		find_unit(char **map);
static t_card	find_player_pos(t_player *player, char **map);
static void		set_vdirection(t_player *player, t_tool *tools, t_card view);

void	init_player(t_player *player, t_data *data)
{
	float	unit;
	t_card	start_view;

	unit = find_unit(data->map);
	data->tools.unit = unit;
	start_view = find_player_pos(player, data->map);
	data->map[player->indexs[Y]][player->indexs[X]] = '0';
	player->pos[X] = (player->indexs[X] * unit + unit / 3.0f);
	player->pos[Y] = (player->indexs[Y] * unit + unit / 3.0f);
	set_vdirection(player, &data->tools, start_view);
	player->speed = 3.0f;
	player->height = HEIGHT / 2;
}

static void	set_vdirection(t_player *player, t_tool *tools, t_card start)
{
	if (start == NO)
	{
		tools->dir[X] = 0.0f;
		tools->dir[Y] = -1.0f;
		player->angle = 90.0f;
	}
	else if (start == SO)
	{
		tools->dir[X] = 0.0f;
		tools->dir[Y] = 1.0f;
		player->angle = 270;
	}
	else if (start == EA)
	{
		tools->dir[Y] = 0.0f;
		tools->dir[X] = 1.0f;
		player->angle = 0.0f;
	}
	else
	{
		tools->dir[Y] = 0.0f;
		tools->dir[X] = -1.0f;
		player->angle = 180.0f;
	}
}

static int	find_unit(char **map)
{
	int	len_x;
	int	len_y;
	int	i;

	len_y = ft_array_len(map);
	i = -1;
	while (map[++i])
	{
		len_x = (int)ft_strlen(map[i]);
		if (map[i + 1] && len_x < (int)ft_strlen(map[i + 1]))
			len_x = (int)ft_strlen(map[i + 1]);
	}
	if (len_x > len_y)
		i = WIDTH / len_x;
	else
		i = WIDTH / len_y;
	while (1)
	{
		if (i * len_x + i < WIDTH && i * len_y + i < HEIGHT)
			break ;
		else
			i--;
	}
	return (i);
}

static t_card	find_player_pos(t_player *player, char **map)
{
	int	i;
	int	find;
	int	len;

	i = -1;
	while (map[++i])
	{
		len = ft_strlen(map[i]);
		find = ft_strcspn(map[i], "NSEW");
		if (find < len)
			break ;
	}
	player->indexs[X] = find;
	player->indexs[Y] = i;
	if (map[i] && map[i][find] == 'N')
		return (NO);
	else if (map[i] && map[i][find] == 'S')
		return (SO);
	else if (map[i] && map[i][find] == 'E')
		return (EA);
	else
		return (WE);
}
