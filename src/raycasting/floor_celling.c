/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_celling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:13:16 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/12 10:59:59 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	init_struct_floor(t_data *data, int y)
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

static void	draw_pixel_mandatory(t_data *data, int x, int y)
{
	if (data->floor_c->is_floor)
		my_mlx_pixel_put(data->img, x, y,
			alpha(data->floor_c->floor_alpha, (int)0xFF000000,
				get_color(1, data->map.floor[0], data->map.floor[1],
					data->map.floor[2])));
	else
		my_mlx_pixel_put(data->img, x, y,
			alpha(1 - data->floor_c->ceil_alpha, (int)0xFF000000,
				get_color(1, data->map.ceiling[0], data->map.ceiling[1],
					data->map.ceiling[2])));
}

static void	draw_pixel_floor_celling(t_data *data, int x, int y)
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
	if (data->tex_floor_c)
	{
		if (data->floor_c->is_floor)
			my_mlx_pixel_put(data->img, x, y,
				alpha(data->floor_c->floor_alpha, (int)0xFF000000,
					ft_get_pixel_img(data->line->texture[4],
						tex_floor.x, tex_floor.y)));
		else
			my_mlx_pixel_put(data->img, x, y,
				alpha(1 - data->floor_c->ceil_alpha, (int)0xFF000000,
					ft_get_pixel_img(data->line->texture[5],
						tex_floor.x, tex_floor.y)));
	}
	else
		draw_pixel_mandatory(data, x, y);
}

static void	init_alpha(t_data *data, int y)
{
	int	half_height;
	int	offset;

	offset = M_H * 0.1;
	half_height = (int)(M_H * 0.5) + data->player.offset_y;
	if (y < half_height)
	{
		data->floor_c->ceil_alpha = (double)y / (half_height - offset);
		if (data->floor_c->ceil_alpha > 1)
			data->floor_c->ceil_alpha = 1;
		if (data->floor_c->ceil_alpha < 0)
			data->floor_c->ceil_alpha = 1;
		data->floor_c->floor_alpha = 0;
	}
	else
	{
		data->floor_c->floor_alpha
			= ((double)y - half_height) / (half_height + (offset * 2));
		if (data->floor_c->floor_alpha > 1)
			data->floor_c->floor_alpha = 1;
		data->floor_c->ceil_alpha = 0;
	}
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
		if (data->fog)
			init_alpha(data, y);
		else
		{
			data->floor_c->floor_alpha = 1;
			data->floor_c->ceil_alpha = 0;
		}
		x = 0;
		while (x < M_W)
		{
			draw_pixel_floor_celling(data, x, y);
			x++;
		}
		y++;
	}
}
