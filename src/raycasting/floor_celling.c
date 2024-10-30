/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_celling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:13:16 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/24 15:50:14 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_struct_floor(t_data *data, int y)
{
	data->floor_c->is_floor = y > M_H * 0.5 + data->player.offset_y;
	data->floor_c->ray_dir_x0 = data->player.v_dir[0] - data->player.v_plane[0];
	data->floor_c->ray_dir_y0 = data->player.v_dir[1] - data->player.v_plane[1];
	data->floor_c->ray_dir_x1 = data->player.v_dir[0] + data->player.v_plane[0];
	data->floor_c->ray_dir_y1 = data->player.v_dir[1] + data->player.v_plane[1];
	if (data->floor_c->is_floor)
		data->floor_c->p = y - M_H * 0.5 - data->player.offset_y;
	else
		data->floor_c->p = M_H * 0.5 - y + data->player.offset_y;
	data->floor_c->row_dist = 0.5 * M_H / data->floor_c->p;
	data->floor_c->floor_step_x = data->floor_c->row_dist
		* (data->floor_c->ray_dir_x1 - data->floor_c->ray_dir_x0) / M_W;
	data->floor_c->floor_step_y = data->floor_c->row_dist
		* (data->floor_c->ray_dir_y1 - data->floor_c->ray_dir_y0) / M_W;
	data->floor_c->floor_x = data->player.position[0]
		+ data->floor_c->row_dist * data->floor_c->ray_dir_x0;
	data->floor_c->floor_y = data->player.position[1]
		+ data->floor_c->row_dist * data->floor_c->ray_dir_y0;
}

void	draw_pixel_floor_celling(t_data *data, int x, int y)
{
	t_point	tex_floor;

	tex_floor.x = (int)(data->line->texture[5 - data->floor_c->is_floor].width
			* (data->floor_c->floor_x - (int)data->floor_c->floor_x))
		& (data->line->texture[5 - data->floor_c->is_floor].width - 1);
	tex_floor.y = (int)(data->line->texture[5 - data->floor_c->is_floor].height
			* (data->floor_c->floor_y - (int)data->floor_c->floor_y))
		& (data->line->texture[5 - data->floor_c->is_floor].height - 1);
	data->floor_c->floor_x += data->floor_c->floor_step_x;
	data->floor_c->floor_y += data->floor_c->floor_step_y;
	if (data->floor_c->is_floor)
		my_mlx_pixel_put(data->img, x, y,
			ft_get_pixel_img(data->line->texture[4],
				tex_floor.x, tex_floor.y));
	else
		my_mlx_pixel_put(data->img, x, y,
			ft_get_pixel_img(data->line->texture[5],
				tex_floor.x, tex_floor.y));
}

void	draw_floor_celling(t_data *data)
{
	t_floor_celling	floor_c;
	int				y;
	int				x;

	y = 0;
	data->floor_c = &floor_c;
	while (y < M_H)
	{
		init_struct_floor(data, y);
		x = 0;
		while (x < M_W)
		{
			draw_pixel_floor_celling(data, x, y);
			x++;
		}
		y++;
	}
}
