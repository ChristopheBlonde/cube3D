/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 08:14:51 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/31 11:03:28 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	init_player_sprite(t_data *data)
{
	t_sprite		*sprite;
	t_sprite_slice	slice;

	sprite = new_sprite(data, "./assets/player/orc_walk_000.xpm");
	if (!sprite)
		return (false);
	sprite->animated = true;
	sprite->render.u_div = 1;
	sprite->render.v_div = 1;
	sprite->render.v_move = 340;
	slice.x = 0;
	slice.y = 0;
	slice.width = 320;
	slice.height = 320;
	ft_lstadd_back(&sprite->anim,
			ft_lstnew(ft_slice_sprite(sprite, slice, 20, 1)));
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
