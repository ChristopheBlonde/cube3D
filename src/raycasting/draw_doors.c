/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:58:00 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/07 12:54:39 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

double	calculate_perp_door_dist(t_data *data)
{
	if (data->ray->side == EAST || data->ray->side == WEST)
		return (data->ray->side_dist_x - data->ray->delta_dist_x / 2);
	else
		return (data->ray->side_dist_y - data->ray->delta_dist_y / 2);
}

void	init_tex_line_door(t_data *data)
{
	double	wall_x;
	int		tex_width;

	data->line->tex_num = 6;
	tex_width = get_current_img(data->door_s)->width;
	if (data->ray->side == EAST || data->ray->side == WEST)
		wall_x = data->player.position[1]
			+ data->line->perp_wall_dist * data->ray->ray_dir[1];
	else
		wall_x = data->player.position[0]
			+ data->line->perp_wall_dist * data->ray->ray_dir[0];
	wall_x -= floor(wall_x);
	data->line->tex_x = (int)(wall_x * (double)(tex_width));
	if ((data->ray->side == EAST || data->ray->side == WEST)
		&& data->ray->ray_dir[0] > 0)
		data->line->tex_x = tex_width - data->line->tex_x - 1;
	if ((data->ray->side == SOUTH || data->ray->side == NORTH)
		&& data->ray->ray_dir[1] < 0)
		data->line->tex_x = tex_width - data->line->tex_x - 1;
}

static void	init_door_line(t_data *data, int x, t_door *door)
{
	data->line->perp_wall_dist = door->zdist[x];
	data->line->line_height = (M_H / data->line->perp_wall_dist);
	data->line->draw_start = (-data->line->line_height / 2 + M_H / 2)
		+ data->player.offset_y;
	if (data->line->draw_start < 0)
		data->line->draw_start = 0;
	data->line->draw_end = (data->line->line_height / 2 + M_H / 2)
		+ data->player.offset_y;
	if (data->line->draw_end >= M_H)
		data->line->draw_end = M_H - 1;
	init_tex_line_door(data);
}

static void	draw_texture_color(t_data *data, int x, int i, t_door *door)
{
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;
	t_img	texture;

	data->ray->dalpha = get_alpha(door->zdist[x]);
	texture = *get_current_img(data->door_s);
	step = 1.0 * texture.height / data->line->line_height;
	tex_pos = (data->line->draw_start - data->player.offset_y - M_H / 2
			+ data->line->line_height / 2) * step;
	while (i < data->line->draw_end)
	{
		tex_y = (int)tex_pos & (texture.height - 1);
		tex_pos += step;
		color = ft_get_pixel_img(texture, data->line->tex_x, tex_y);
		if (color != (int)0xFF000000)
			my_mlx_pixel_put(data->img, x, i,
				alpha(1 - data->ray->dalpha, (int)0xFF000000, color));
		i++;
	}
}

void	draw_doors(t_data *data, int x)
{
	t_door	*door;
	t_list	*lst;
	t_anim	*anim;

	lst = (t_list *)data->door_s->anim;
	anim = (t_anim *)lst->content;
	door = get_door(data, data->ray->map[0], data->ray->map[1]);
	if (!door)
		return ;
	anim->current_frame_num = door->curr_frame;
	init_door_line(data, x, door);
	draw_texture_color(data, x, data->line->draw_start, door);
}
