/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkdoor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:45:21 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/23 16:41:10 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_door	*get_door(t_data *data, int x, int y)
{
	int		i;
	t_door	*door;

	door = NULL;
	i = -1;
	while (++i < (int)data->map.nb_doors)
	{
		if (data->map.doors[i].pos_x == x && data->map.doors[i].pos_y == y)
			return (&data->map.doors[i]);
	}
	return (door);
}

bool	checkdoor(t_data *data)
{
	int		y;
	int		x;
	t_door	*door;

	y = data->ray->map[1];
	x = data->ray->map[0];
	door = get_door(data, x, y);
	if (door)
	{
		if (door->dir == NS)
			if (data->ray->side_dist_x > data->ray->side_dist_y - 0.5
				* data->ray->delta_dist_y)
				return (true);
		if (door->dir == EW)
			if (data->ray->side_dist_x - 0.5 * data->ray->delta_dist_x
				< data->ray->side_dist_y)
				return (true);
	}
	return (false);
}
