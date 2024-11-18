/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:00:59 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/18 11:27:29 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	rotate_cam(t_data *data, double speed)
{
	double	n_pos_x;
	double	n_pos_y;
	double	x;
	double	y;
	double	angle;

	angle = speed * -1;
	n_pos_x = data->player.position[0] - data->player.player_s->pos_x;
	n_pos_y = data->player.position[1] - data->player.player_s->pos_y;
	x = n_pos_x * cos(angle) + n_pos_y * sin(angle)
		+ data->player.player_s->pos_x;
	y = -n_pos_x * sin(angle) + n_pos_y * cos(angle)
		+ data->player.player_s->pos_y;
	if (inside_a_wall(data, (int)x, (int)y, &data->map))
		return (false);
	data->player.position[0] = x;
	data->player.position[1] = y;
	return (true);
}

void	rotate_player(t_data *data, double speed)
{
	t_player	*p;
	double		tmp;

	if (data->player.active)
		if (!rotate_cam(data, speed))
			return ;
	p = &data->player;
	p->dir_angle += speed;
	tmp = p->v_dir[0];
	p->v_dir[0] = cos(speed) * tmp - sin(speed) * p->v_dir[1];
	p->v_dir[1] = sin(speed) * tmp + cos(speed) * p->v_dir[1];
	tmp = p->v_plane[0];
	p->v_plane[0] = cos(speed) * tmp - sin(speed) * p->v_plane[1];
	p->v_plane[1] = sin(speed) * tmp + cos(speed) * p->v_plane[1];
}
