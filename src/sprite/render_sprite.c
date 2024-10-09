/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:19:52 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/09 09:12:14 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

static void	draw_sprite(t_data *data, t_rend *render, int i)
{
	int	x;
	int	y;
	int	d;

	x = render->start_x - 1;
	while (++x < render->end_x)
	{
		render->tex_x = (int)((256 * (x - (-render->s_w / 2 + render->s_sc_x))
					* data->arr_s[i]->width / render->s_w) / 256);
		if (render->trf_y > 0 && x > 0 && x < M_W
			&& render->trf_y < data->zdist[x])
		{
			y = render->start_y - 1;
			while (++y < render->end_y)
			{
				d = y * 256 - M_H * 128 + render->s_h * 128;
				render->tex_y = ((d * data->arr_s[i]->height) / render->s_h)
					/ 256;
				put_pixel_win(data, x, y,
					ft_get_pixel_img(*data->arr_s[i]->img,
						render->tex_x, render->tex_y));
			}
		}
	}
}

static void	find_render_size(t_rend *render)
{
	render->start_y = -render->s_h / 2 + M_H / 2;
	if (render->start_y < 0)
		render->start_y = 0;
	render->end_y = render->s_h / 2 + M_H / 2;
	if (render->end_y >= M_H)
		render->end_y = M_H - 1;
	render->s_w = abs(((int)(M_H / render->trf_y)));
	render->start_x = -render->s_w / 2 + render->s_sc_x;
	if (render->start_x < 0)
		render->start_x = 0;
	render->end_x = render->s_w / 2 + render->s_sc_x;
	if (render->end_x >= M_W)
		render->end_x = M_W - 1;
}

void	render_sprite(t_data *data)
{
	int		i;
	t_rend	render;

	i = 0;
	while (data->arr_s[i])
	{
		render = data->arr_s[i]->render;
		render.cam_x = data->arr_s[i]->pos_x - data->player.position[0];
		render.cam_y = data->arr_s[i]->pos_y - data->player.position[1];
		render.inv_det = 1.0 / (data->player.v_plane[0] * data->player.v_dir[1]
				- data->player.v_dir[0] * data->player.v_plane[1]);
		render.trf_x = render.inv_det * (data->player.v_dir[1] * render.cam_x
				- data->player.v_dir[0] * render.cam_y);
		render.trf_y = render.inv_det * (-data->player.v_plane[1] * render.cam_x
				+ data->player.v_plane[0] * render.cam_y);
		render.s_sc_x = (int)((M_W / 2) * (1 + render.trf_x / render.trf_y));
		render.s_h = abs(((int)(M_H / render.trf_y)));
		find_render_size(&render);
		draw_sprite(data, &render, i);
		i++;
	}
}
