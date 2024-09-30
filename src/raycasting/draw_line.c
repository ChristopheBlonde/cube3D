/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:05:21 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/30 16:12:54 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_line.h"
#include "graph.h"

double	calculate_perp_wall_dist(t_data *data)
{
	if (data->ray->side == 0)
		return (data->ray->side_dist_x - data->ray->delta_dist_x);
	else
		return (data->ray->side_dist_y - data->ray->delta_dist_y);
}

void	init_line(t_data *data)
{
	data->line->ceiling_color = get_color(1, data->map.ceiling[0],
			data->map.ceiling[1], data->map.ceiling[2]);
	data->line->floor_color = get_color(1, data->map.floor[0],
			data->map.floor[1], data->map.floor[2]);
	data->line->perp_wall_dist = calculate_perp_wall_dist(data);
	data->line->line_height = (M_H / data->line->perp_wall_dist);
	data->line->draw_start = -data->line->line_height / 2 + M_H / 2;
	if (data->line->draw_start < 0)
		data->line->draw_start = 0;
	data->line->draw_end = data->line->line_height / 2 + M_H / 2;
	if (data->line->draw_end >= M_H)
		data->line->draw_end = M_H - 1;
}

void	pixel_line(t_data *data, int x)
{
	int	i;

	i = 0;
	while (i < data->line->draw_start)
	{
		my_mlx_pixel_put(data->img, x, i, data->line->ceiling_color);
		i++;
	}
	while (i < data->line->draw_end)
	{
		if (data->ray->side)
			my_mlx_pixel_put(data->img, x, i, 0x00FC5185);
		else
			my_mlx_pixel_put(data->img, x, i, 0x00364F6B);
		i++;
	}
	while (i < M_H - 1)
	{
		my_mlx_pixel_put(data->img, x, i, data->line->floor_color);
		i++;
	}
}

void	draw_line(t_data *data, int x)
{
	init_line(data);
	pixel_line(data, x);
}
