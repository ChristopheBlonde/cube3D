/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:19:52 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/15 12:14:02 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

static void	draw_sprite(t_data *data, t_rend *render, t_img *img)
{
	int	x;
	int	y;
	int	d;

	x = render->start_x - 1;
	while (++x < render->end_x)
	{
		render->tex_x = (int)((256 * (x - (-render->s_w / 2 + render->s_sc_x))
					* img->width / render->s_w) / 256);
		if (render->trf_y > 0 && x > 0 && x < M_W
			&& render->trf_y < data->zdist[x])
		{
			y = render->start_y - 1;
			while (++y < render->end_y)
			{
				d = (y - render->v_m_sc) * 256 - M_H * 128 + render->s_h * 128;
				render->tex_y = ((d * img->height) / render->s_h)
					/ 256;
				put_pixel_win(data, x, y,
					ft_get_pixel_img(*img, render->tex_x, render->tex_y));
			}
		}
	}
}

static void	find_render_size(t_rend *render)
{
	render->start_y = -render->s_h / 2 + M_H / 2 + render->v_m_sc;
	if (render->start_y < 0)
		render->start_y = 0;
	render->end_y = render->s_h / 2 + M_H / 2 + render->v_m_sc;
	if (render->end_y >= M_H)
		render->end_y = M_H - 1;
	render->s_w = abs(((int)(M_H / render->trf_y))) / render->u_div;
	render->start_x = -render->s_w / 2 + render->s_sc_x;
	if (render->start_x < 0)
		render->start_x = 0;
	render->end_x = render->s_w / 2 + render->s_sc_x;
	if (render->end_x >= M_W)
		render->end_x = M_W - 1;
}

static void	update_anim(t_sprite *sprite, t_img **img)
{
	t_list	*lst_anim;
	t_list	*frames;
	t_anim	*a;

	if (!sprite->animated)
		*img = (t_img *)sprite->img;
	else
	{
		lst_anim = (t_list *)sprite->anim;
		a = (t_anim *)lst_anim->content;
		frames = (t_list *)a->frames;
		*img = (t_img *)ft_lstget(frames, a->current_frame_num)->content;
	}
}

void	render_sprite(t_data *data)
{
	int		i;
	t_rend	render;
	t_img	*img;

	i = 0;
	sort_sprites(data);
	while (data->arr_s[i])
	{
		update_anim(data->arr_s[i], &img);
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
		render.v_m_sc = (int)(render.v_move / render.trf_y);
		render.s_h = abs(((int)(M_H / render.trf_y))) / render.v_div;
		find_render_size(&render);
		draw_sprite(data, &render, img);
		i++;
	}
}
