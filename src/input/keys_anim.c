/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:21:53 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/26 12:23:53 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	handle_player_visibility(t_data *data)
{
	if (data->player.active)
		data->player.active = false;
	else
	{
		if (data->visible_sprite)
			data->player.active = true;
	}
	data->player.keyboard[KEY_P] = 0;
}

void	handle_keys_anim(t_data *data)
{
	int	*keyboard;

	if (!data->player.active)
		return ;
	keyboard = data->player.keyboard;
	if (keyboard[KEY_W] && keyboard[KEY_A])
		data->player.player_s->lst_nb = 30;
	else if (keyboard[KEY_W] && keyboard[KEY_D])
		data->player.player_s->lst_nb = 18;
	else if (keyboard[KEY_S] && keyboard[KEY_A])
		data->player.player_s->lst_nb = 26;
	else if (keyboard[KEY_S] && keyboard[KEY_D])
		data->player.player_s->lst_nb = 22;
	else if (keyboard[KEY_W])
		data->player.player_s->lst_nb = 16;
	else if (keyboard[KEY_A])
		data->player.player_s->lst_nb = 28;
	else if (keyboard[KEY_S])
		data->player.player_s->lst_nb = 24;
	else if (keyboard[KEY_D])
		data->player.player_s->lst_nb = 20;
	update_anim_player(data->player.player_s);
}

int	handle_keyrelease_anim(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->player.player_s->lst_nb = 0;
	if (keysym == XK_a)
		data->player.player_s->lst_nb = 12;
	if (keysym == XK_s)
		data->player.player_s->lst_nb = 8;
	if (keysym == XK_d)
		data->player.player_s->lst_nb = 4;
	return (0);
}
