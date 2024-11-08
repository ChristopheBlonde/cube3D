/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:15:36 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/08 15:46:24 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	handle_key_sprite(t_data *data)
{
	int	*keyboard;

	keyboard = data->player.keyboard;
	if (keyboard[KEY_SPRITE])
	{
		if (data->visible_sprite)
			data->visible_sprite = false;
		else
			data->visible_sprite = true;
		keyboard[KEY_SPRITE] = 0;
	}
}

void	handle_keys_bonus(t_data *data)
{
	int	*keyboard;

	keyboard = data->player.keyboard;
	if (keyboard[KEY_FOG])
	{
		if (data->fog)
			data->fog = false;
		else
			data->fog = true;
		keyboard[KEY_FOG] = 0;
	}
	if (keyboard[KEY_DOOR])
	{
		if (data->visible_door)
			data->visible_door = false;
		else
			data->visible_door = true;
		keyboard[KEY_DOOR] = 0;
	}
	handle_key_sprite(data);
}
