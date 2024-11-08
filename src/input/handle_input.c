/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:33:48 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/08 15:14:51 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	handle_movement_and_rotation(t_data *data)
{
	int	*keyboard;

	keyboard = data->player.keyboard;
	if (keyboard[KEY_W])
		move_player(data, KEY_W, 0.12);
	if (keyboard[KEY_A])
		move_player(data, KEY_A, 0.08);
	if (keyboard[KEY_S])
		move_player(data, KEY_S, 0.12);
	if (keyboard[KEY_D])
		move_player(data, KEY_D, 0.08);
	if (keyboard[KEY_RIGHT])
		rotate_player(&data->player, MOUSE_SPEED * 10 * PI);
	if (keyboard[KEY_LEFT])
		rotate_player(&data->player, -MOUSE_SPEED * 10 * PI);
	if (keyboard[KEY_F])
		handle_action(data);
	if (keyboard[KEY_P])
		handle_player_visibility(data);
	update_player_pos(data);
	handle_keys_anim(data);
	handle_keys_bonus(data);
}

void	check_y_axis(t_data *data, int y, int old_y)
{
	static int	offset_y = 0;

	offset_y -= (y - old_y);
	if (offset_y > 450)
		offset_y = 450;
	if (offset_y < -450)
		offset_y = -450;
	data->player.offset_y = offset_y;
}

int	check_key_mouse(t_data *data)
{
	if (data->player.keyboard[KEY_MOUSE])
	{
		if (!data->mouse)
		{
			data->mouse = true;
			mlx_mouse_hide(data->win->mlx_ptr, data->win->win_ptr);
			mlx_mouse_move(data->win->mlx_ptr,
				data->win->win_ptr, M_W * 0.5, M_H * 0.5);
		}
		else
		{
			data->mouse = false;
			mlx_mouse_show(data->win->mlx_ptr, data->win->win_ptr);
			data->player.offset_y = 0;
		}
		data->player.keyboard[KEY_MOUSE] = false;
	}
	if (!data->mouse)
		return (true);
	return (false);
}

void	handle_mouse(t_data *data)
{
	int			x;
	int			y;
	static int	old_x = M_W * 0.5;
	static int	old_y = M_H * 0.5;

	if (check_key_mouse(data))
		return ;
	mlx_mouse_get_pos(data->win->mlx_ptr, data->win->win_ptr, &x, &y);
	rotate_player(&data->player, MOUSE_SPEED * ((x - old_x)));
	check_y_axis(data, y, old_y);
	old_x = x;
	old_y = y;
	if (x <= 0.1 * M_W || x >= 0.9 * M_W || y <= 0.1 * M_H || y >= 0.9 * M_H)
	{
		mlx_mouse_move(data->win->mlx_ptr,
			data->win->win_ptr, M_W * 0.5, M_H * 0.5);
		old_x = M_W * 0.5;
		old_y = M_H * 0.5;
	}
}

int	handle_input(t_data *data)
{
	handle_mouse(data);
	handle_movement_and_rotation(data);
	handle_minimap_changed(data);
	return (0);
}
