/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_drawline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:30:26 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/29 12:17:10 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_line.h"

double	calculate_perp_wall_dist(t_data *data)
{
	t_door *door;

	door = get_door(data, data->ray->map[0], data->ray->map[1]);
	if (data->ray->side == EAST || data->ray->side == WEST)
	{
		if (door)
			return (data->ray->side_dist_x - data->ray->delta_dist_x / 2);
		else
			return (data->ray->side_dist_x - data->ray->delta_dist_x);
	}
	else
	{
		if (door)
			return (data->ray->side_dist_y - data->ray->delta_dist_y / 2);
		else
			return (data->ray->side_dist_y - data->ray->delta_dist_y);
	}
}


void	calculate_doors(t_data *data, bool *door, bool save)
{
	if (save)
	{
		*door = true;
		data->ray->door_side = data->ray->side;
		data->ray->door[0] = data->ray->map[0];
		data->ray->door[1] = data->ray->map[1];
		data->ray->door_dist_x = data->ray->side_dist_x;
		data->ray->door_dist_y = data->ray->side_dist_y;
	}
	else
	{
		data->ray->side = data->ray->door_side;
		data->ray->map[0] = data->ray->door[0];
		data->ray->map[1] = data->ray->door[1];
		data->ray->side_dist_x = data->ray->door_dist_x;
		data->ray->side_dist_y = data->ray->door_dist_y;
		*door = false;
	}
}
