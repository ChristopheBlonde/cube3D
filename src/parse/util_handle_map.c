/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_handle_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:19:36 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/21 13:55:41 by cblonde          ###   ########.fr       */
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

bool	init_doors(t_map *map)
{
	int		x;
	int		y;
	int		curr;
	t_door	door;

	curr = -1;
	map->doors = (t_door *)ft_calloc(map->nb_doors + 1, sizeof(t_door));
	if (!map->doors)
		return (false);
	y = -1;
	while (++y < (int)map->height)
	{
		x = -1;
		while (++x < (int)map->width)
		{
			if (map->map[y][x] == 'D')
			{
				door.pos_x = x;
				door.pos_y = y;
				door.status = CLOSE;
				map->doors[++curr] = door;
			}
		}
	}
	return (true);
}
