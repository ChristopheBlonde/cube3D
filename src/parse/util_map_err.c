/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:12:47 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/26 13:45:35 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	missing_att(t_map *map)
{
	if (map->height == 0)
		return (err_attribute(0));
	if (map->width == 0)
		return (err_attribute(1));
	if (!map->no || !map->so || !map->we || !map->ea)
		return (err_attribute(2));
	if (map->width * map->height > 1000 * 150)
		return (err_attribute(3));
	if (map->floor[0] == -1 && map->floor[1] == -1 && map->floor[2] == -1)
		return (err_attribute(4));
	if (map->ceiling[0] == -1 && map->ceiling[1] == -1 && map->ceiling[2] == -1)
		return (err_attribute(5));
	if ((map->player.position[0] == 0 && map->player.position[1] == 0)
		|| map->player.dir == NONE)
		return (err_attribute(6));
	return (true);
}
