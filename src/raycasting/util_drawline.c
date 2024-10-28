/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_drawline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:30:26 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/28 17:57:39 by cblonde          ###   ########.fr       */
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
