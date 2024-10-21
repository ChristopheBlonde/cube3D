/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:33:48 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/17 07:33:14 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	zero_input(int *keyboard, int size)
{
	int	i;

	i = 0;
	while (i < size && !keyboard[i])
		i++;
	if (keyboard[i])
		return (0);
	return (1);
}

void	handle_movement_and_rotation(t_data *data)
{
	int	*keyboard;

	keyboard = data->player.keyboard;
	if (keyboard[KEY_W])
		move_player(&data->player, &data->map, KEY_W, 0.12);
	if (keyboard[KEY_A])
		move_player(&data->player, &data->map, KEY_A, 0.08);
	if (keyboard[KEY_S])
		move_player(&data->player, &data->map, KEY_S, 0.12);
	if (keyboard[KEY_D])
		move_player(&data->player, &data->map, KEY_D, 0.08);
	if (keyboard[KEY_RIGHT])
		rotate_player(&data->player, 0.01 * PI);
	if (keyboard[KEY_LEFT])
		rotate_player(&data->player, -0.01 * PI);
}

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

int	handle_input(t_data *data)
{
	int	*keyboard;

	keyboard = data->player.keyboard;
	if (zero_input(keyboard, KEY_NB))
		return (1);
	handle_movement_and_rotation(data);
	handle_minimap_changed(data);
	return (0);
}
