/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:45:31 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/25 12:55:12 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	init_map(t_map *map)
{
	int	i;

	i = -1;
	map->height = 0;
	map->width = 0;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->map = NULL;
	map->sprites = NULL;
	map->nb_doors = 0;
	map->doors = NULL;
	map->sprite_nb = 0;
	map->curr_sprite = 0;
	while (++i < 3)
	{
		map->floor[i] = 0;
		map->ceiling[i] = 0;
	}
	map->player.pos.x = 0;
	map->player.pos.y = 0;
	map->player.dir = NONE;
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->no)
		free(map->no);
	map->no = NULL;
	if (map->so)
		free(map->so);
	map->so = NULL;
	if (map->we)
		free(map->we);
	map->we = NULL;
	if (map->ea)
		free(map->ea);
	map->ea = NULL;
	if (map->map)
		ft_free_array((void **)map->map);
	map->map = NULL;
	if (map->sprites)
		ft_free_array((void **)map->sprites);
	map->sprites = NULL;
	if (map->doors)
		free(map->doors);
	map->doors = NULL;
}
