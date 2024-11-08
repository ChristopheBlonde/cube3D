/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:18:43 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/08 12:21:41 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	handle_minimap_changed(t_data *data)
{
	int	*keyboard;

	keyboard = data->player.keyboard;
	if (keyboard[KEY_MAP])
	{
		if (data->mnmap->minimap)
			data->mnmap->minimap = false;
		else
			data->mnmap->minimap = true;
		keyboard[KEY_MAP] = 0;
	}
	if (keyboard[KEY_UP_MAP])
	{
		if (data->mnmap->minimap && data->mnmap->size < 22)
			data->mnmap->size += 2;
		keyboard[KEY_UP_MAP] = 0;
	}
	if (keyboard[KEY_DOWN_MAP])
	{
		if (data->mnmap->minimap && data->mnmap->size > 4)
			data->mnmap->size -= 2;
		keyboard[KEY_DOWN_MAP] = 0;
	}
}
