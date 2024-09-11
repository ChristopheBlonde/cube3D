/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:45:31 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/11 15:45:27 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	init_map(t_map *map)
{
	int	i;

	i = -1;
	map->height = -1;
	map->width = -1;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	while (++i < 3)
	{
		map->floor[i] = -1;
		map->ceiling[i] = -1;
	}
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->no)
	{
		free(map->no);
		map->no = NULL;
	}
	if (map->so)
	{
		free(map->so);
		map->so = NULL;
	}
	if (map->we)
	{
		free(map->we);
		map->we = NULL;
	}
	if (map->ea)
	{
		free(map->ea);
		map->ea = NULL;
	}
}
