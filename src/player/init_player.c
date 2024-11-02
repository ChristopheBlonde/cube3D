/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 08:14:51 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/31 15:40:06 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	finish_move000(t_data *data)
{
	t_sprite	*sprite;
	t_list		*lst;
	t_anim		*anim;

	sprite = data->player.player_s;
	lst = sprite->anim;
	anim = lst->content;
	lst = anim->frames;
	if (!data->player.keyboard[KEY_W] && anim->current_frame_num != 14)
	{
		anim->_tmp_delay = 0;
		if (anim->current_frame_num < 14 && anim->current_frame_num > 4)
		{
			anim->current_frame_num++;
			anim->current_frame_num %= ft_lstsize(lst);
		}
		else
		{
			if (anim->current_frame_num == 0)
				anim->current_frame_num = 19;
			else
				anim->current_frame_num--;
		}
	}
}

static void	init_player_img(t_sprite *sprite)
{
	t_list	*lst_anim;
	t_anim	*anim;

	sprite->animated = true;
	sprite->render.u_div = 1;
	sprite->render.v_div = 1;
	sprite->render.v_move = 340;
	lst_anim = sprite->anim;
	anim = lst_anim->content;
	anim->current_frame_num = 14;
}

bool	init_player_sprite(t_data *data)
{
	t_sprite		*sprite;
	t_sprite_slice	slice;

	sprite = new_sprite(data, "./assets/player/orc_walk_000.xpm");
	if (!sprite)
		return (false);
	slice.x = 0;
	slice.y = 0;
	slice.width = 320;
	slice.height = 320;
	ft_lstadd_back(&sprite->anim,
			ft_lstnew(ft_slice_sprite(sprite, slice, 20, 1)));
	init_player_img(sprite);
	data->player.player_s = sprite;
	update_player_pos(data);
	return (true);
}

void	update_player_pos(t_data *data)
{
	data->player.player_s->pos_x
		= data->player.position[0] + data->player.v_dir[0];
	data->player.player_s->pos_y
		= data->player.position[1] + data->player.v_dir[1];
}
