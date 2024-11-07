/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:05:21 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/07 12:53:41 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_line.h"

static void	init_tex_line(t_data *data, int image, t_door *door)
{
	double	wall_x;
	int		tex_width;

	if (door)
		tex_width = get_current_img(data->door_s)->width;
	else if (image)
		tex_width = data->line->texture[image].width;
	else
		tex_width = data->line->texture[data->ray->side - 1].width;
	data->line->tex_num = data->ray->side;
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

static void	init_line(t_data *data, int image, t_door *door)
{
	data->line->ceiling_color = get_color(1, data->map.ceiling[0],
			data->map.ceiling[1], data->map.ceiling[2]);
	data->line->floor_color = get_color(1, data->map.floor[0],
			data->map.floor[1], data->map.floor[2]);
	data->line->perp_wall_dist = calculate_perp_wall_dist(data);
	data->line->line_height = (M_H / data->line->perp_wall_dist);
	data->line->draw_start = (-data->line->line_height / 2 + M_H / 2)
		+ data->player.offset_y;
	if (data->line->draw_start < 0)
		data->line->draw_start = 0;
	data->line->draw_end = (data->line->line_height / 2 + M_H / 2)
		+ data->player.offset_y;
	if (data->line->draw_end >= M_H)
		data->line->draw_end = M_H - 1;
	init_tex_line(data, image, door);
}

static void	draw_texture_color(t_data *data, int x, int i, t_img *image)
{
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;
	t_img	texture;

	data->ray->dalpha = get_alpha(data->zdist[x]);
	texture = *image;
	step = 1.0 * texture.height / data->line->line_height;
	tex_pos = (data->line->draw_start - data->player.offset_y - M_H / 2
			+ data->line->line_height / 2) * step;
	while (i < data->line->draw_end)
	{
		tex_y = (int)tex_pos & (texture.height - 1);
		tex_pos += step;
		color = ft_get_pixel_img(texture, data->line->tex_x, tex_y);
		if (image && color != (int)0xFF000000)
			my_mlx_pixel_put(data->img, x, i,
				alpha(data->ray->dalpha, color, (int)0xFF000000));
		if (!image)
			my_mlx_pixel_put(data->img, x, i,
				alpha(data->ray->dalpha, color, (int)0xFF000000));
		i++;
	}
}

static void	pixel_line(t_data *data, int x, int image, t_door *door)
{
	t_list	*lst_anim;
	t_anim	*anim;

	if (door)
	{
		lst_anim = (t_list *)data->door_s->anim;
		anim = (t_anim *)lst_anim->content;
		anim->current_frame_num = door->curr_frame;
		draw_texture_color(data, x, data->line->draw_start,
			get_current_img(data->door_s));
	}
	else
		draw_texture_color(data, x, data->line->draw_start,
			&data->line->texture[image]);
}

void	draw_line(t_data *data, int x)
{
	init_line(data, data->ray->side - 1, NULL);
	data->zdist[x] = data->line->perp_wall_dist;
	pixel_line(data, x, data->ray->side - 1, NULL);
}
