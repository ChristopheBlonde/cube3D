/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:33:48 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/04 16:55:29 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	handle_movement_and_rotation(t_data *data)
{
	int	*keyboard;

	keyboard = data->player.keyboard;
	if (keyboard[KEY_W])
	{
		move_player(&data->player, &data->map, KEY_W, 0.12);
		data->player.player_s->lst_nb = 0;
		update_anim_player(data->player.player_s);
	}
	if (keyboard[KEY_A])
	{
		move_player(&data->player, &data->map, KEY_A, 0.08);
		data->player.player_s->lst_nb = 12;
		update_anim_player(data->player.player_s);
	}
	if (keyboard[KEY_S])
	{
		move_player(&data->player, &data->map, KEY_S, 0.12);
		data->player.player_s->lst_nb = 8;
		update_anim_player(data->player.player_s);
	}
	if (keyboard[KEY_D])
	{
		move_player(&data->player, &data->map, KEY_D, 0.08);
		data->player.player_s->lst_nb = 4;
		update_anim_player(data->player.player_s);
	}
	if (keyboard[KEY_RIGHT])
		rotate_player(&data->player, MOUSE_SPEED);
	if (keyboard[KEY_LEFT])
		rotate_player(&data->player, -MOUSE_SPEED);
	if (keyboard[KEY_F])
		handle_action(data);
	update_player_pos(data);
}

void	check_y_axis(t_data *data, int y)
{
	static double	offset_y = 0;

	offset_y -= (y - M_H / 2);
	if (offset_y > 450)
		offset_y = 450;
	if (offset_y < -450)
		offset_y = -450;
	data->player.offset_y = offset_y;
}

void	handle_mouse(t_data *data)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(data->win->mlx_ptr, data->win->win_ptr, &x, &y);
	if (!(x < 0 || x > M_W || y < 0 || y > M_H))
	{
		rotate_player(&data->player, MOUSE_SPEED * (x - M_W / 2) / 100);
		check_y_axis(data, y);
	}
	mlx_mouse_move(data->win->mlx_ptr,
		data->win->win_ptr, M_W * 0.5, M_H * 0.5);
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
	handle_mouse(data);
	handle_movement_and_rotation(data);
	handle_minimap_changed(data);
	return (0);
}
