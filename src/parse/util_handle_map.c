/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_handle_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:19:36 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/29 09:31:01 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	is_valid_character(t_map *map, int pos[2], size_t *unknow)
{
	int	i;
	int	j;

	i = pos[0];
	j = pos[1];
	if (map->map[i][j] != ' ' && map->map[i][j] != '1'
		&& map->map[i][j] != 'S' && map->map[i][j] != 'N'
		&& map->map[i][j] != 'W' && map->map[i][j] != 'E'
		&& map->map[i][j] != '0' && map->map[i][j] != 'D')
		(*unknow)++;
	if (map->map[i][j] == 'D')
		map->nb_doors++;
}

static void	init_door(t_map *map, t_door *door, int x, int y)
{
	door->pos_x = x;
	door->pos_y = y;
	door->status = CLOSE;
	door->curr_frame = 0;
	door->nb_frames = 4;
	door->delay = 6;
	door->_tmp_delay = 0;
	if ((y > 0 && map->map[y - 1][x] == '1')
		|| (y < (int)map->height - 1 && map->map[y + 1][x] == '1'))
		door->dir = EW;
	else if ((x > 0 && map->map[y][x - 1] == '1')
		|| (x < (int)map->width - 1 && map->map[y][x + 1] == '1'))
		door->dir = NS;
	else
		door->dir = NODIR;
}

bool	init_doors(t_map *map)
{
	int		x;
	int		y;
	int		curr;
	t_door	door;

	curr = -1;
	if (!map->nb_doors)
		return (true);
	map->doors = (t_door *)ft_calloc(map->nb_doors + 1, sizeof(t_door));
	if (!map->doors)
		return (false);
	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] && map->map[y][x] == 'D')
			{
				init_door(map, &door, x, y);
				map->doors[++curr] = door;
			}
		}
	}
	return (true);
}
