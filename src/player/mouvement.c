/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:47:45 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/18 13:23:13 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	move_player_forward(t_data *data, double speed)
{
	t_player	*p;
	t_map		*m;

	p = &data->player;
	m = &data->map;
	if (!inside_a_wall(data, p->position[0] + p->v_dir[0] * speed,
			p->position[1], m))
		p->position[0] += p->v_dir[0] * speed;
	if (!inside_a_wall(data, p->position[0],
			p->position[1] + p->v_dir[1] * speed, m))
		p->position[1] += p->v_dir[1] * speed;
}

static void	move_player_back(t_data *data, double speed)
{
	t_player	*p;
	t_map		*m;

	p = &data->player;
	m = &data->map;
	if (!inside_a_wall(data, p->position[0] - p->v_dir[0] * speed,
			p->position[1], m))
		p->position[0] -= p->v_dir[0] * speed;
	if (!inside_a_wall(data, p->position[0],
			p->position[1] - p->v_dir[1] * speed, m))
		p->position[1] -= p->v_dir[1] * speed;
}

static void	move_player_right(t_data *data, double speed)
{
	t_player	*p;
	t_map		*m;
	double		new_angle;

	p = &data->player;
	m = &data->map;
	new_angle = p->dir_angle + PI * 0.5;
	if (!inside_a_wall(data, p->position[0]
			+ cos(new_angle) * speed, p->position[1], m))
		p->position[0] += cos(new_angle) * speed;
	if (!inside_a_wall(data, p->position[0], p->position[1]
			+ sin(new_angle) * speed, m))
		p->position[1] += sin(new_angle) * speed;
}

static void	move_player_left(t_data *data, double speed)
{
	t_player	*p;
	t_map		*m;
	double		new_angle;

	p = &data->player;
	m = &data->map;
	new_angle = p->dir_angle - PI * 0.5;
	if (!inside_a_wall(data, p->position[0]
			+ cos(new_angle) * speed, p->position[1], m))
		p->position[0] += cos(new_angle) * speed;
	if (!inside_a_wall(data, p->position[0], p->position[1]
			+ sin(new_angle) * speed, m))
		p->position[1] += sin(new_angle) * speed;
}

void	move_player(t_data *data, int keysym, double speed)
{
	if (keysym == KEY_W)
		move_player_forward(data, speed);
	if (keysym == KEY_S)
		move_player_back(data, speed);
	if (keysym == KEY_D)
		move_player_right(data, speed);
	if (keysym == KEY_A)
		move_player_left(data, speed);
	update_player_pos(data);
}
