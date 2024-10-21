/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_drawline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:30:26 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/21 14:05:42 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_line.h"

double	calculate_perp_wall_dist(t_data *data)
{
	if (data->ray->side == EAST || data->ray->side == WEST)
	{
		if (data->map.map[data->ray->map[1]][data->ray->map[0]] == '1')
			return (data->ray->side_dist_x - data->ray->delta_dist_x);
		else
			return (data->ray->side_dist_x - data->ray->delta_dist_x / 2);
	}
	else
	{
		if (data->map.map[data->ray->map[1]][data->ray->map[0]] == '1')
			return (data->ray->side_dist_y - data->ray->delta_dist_y);
		else
			return (data->ray->side_dist_y - data->ray->delta_dist_y / 2);
	}
}
