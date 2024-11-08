/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_drawline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:30:26 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/08 12:24:59 by cblonde          ###   ########.fr       */
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

static void	draw_all_doors(bool *rendered, t_data *data, t_door *door[0], int x)
{
	*rendered = true;
	init_ray(data, x);
	calculating_initial_side_dist(data);
	calculating_ray_size(data, x, true, door);
	draw_doors(data, x);
	data->zdist[x] = door[0]->zdist[x];
	door[0]->zdist[x] = -1;
}

void	render_doors(t_data *data)
{
	int		x;
	int		i;
	t_door	*door[2];
	bool	rendered;

	rendered = false;
	i = -1;
	sort_door(data);
	door[1] = NULL;
	while (++i < (int)data->map.nb_doors)
	{
		x = -1;
		door[0] = &data->map.doors[i];
		while (++x < M_W - 1)
		{
			if (door[0]->zdist[x] > -1)
				draw_all_doors(&rendered, data, door, x);
		}
		if (rendered)
		{
			render_arr_sprites(data);
			rendered = false;
		}
	}
}
