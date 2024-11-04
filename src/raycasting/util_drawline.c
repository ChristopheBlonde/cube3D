/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_drawline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:30:26 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/02 12:31:43 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_line.h"

double	calculate_perp_wall_dist(t_data *data)
{
	if (data->ray->side == EAST || data->ray->side == WEST)
			return (data->ray->side_dist_x - data->ray->delta_dist_x);
	else
			return (data->ray->side_dist_y - data->ray->delta_dist_y);
}

double	get_alpha(double dist)
{
	double	dalpha;

	dalpha = dist * 0.1;
	if (dalpha > 1)
		dalpha = 1;
	return (dalpha);
}

void	init_zdoordist(t_data *data)
{
	int	i;

	i = 0;
	while (i < M_W - 1)
	{
		data->zdoordist[i] = -1;
		i++;
	}
}

void	render_doors(t_data *data)
{
	int	x;

	x = 0;
	while (x < M_W - 1)
	{
		if (data->zdoordist[x] > -1)
		{
			init_ray(data, x);
			calculating_initial_side_dist(data);
			calculating_ray_size(data, x, true);
			draw_doors(data, x);	
			data->zdist[x] = data->zdoordist[x];
		}
		x++;
	}
}
