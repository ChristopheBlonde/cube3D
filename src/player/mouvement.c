/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:47:45 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/23 15:19:21 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	move_player_forward(t_player *p, t_map *m, double speed)
{
	if (!inside_a_wall(p->position[0]
			+ p->v_dir[0] * speed, p->position[1], m))
		p->position[0] += p->v_dir[0] * speed;
	if (!inside_a_wall(p->position[0], p->position[1] + p->v_dir[1] * speed, m))
		p->position[1] += p->v_dir[1] * speed;
}

static void	move_player_back(t_player *p, t_map *m, double speed)
{
	if (!inside_a_wall(p->position[0] - p->v_dir[0] * speed, p->position[1], m))
		p->position[0] -= p->v_dir[0] * speed;
	if (!inside_a_wall(p->position[0], p->position[1] - p->v_dir[1] * speed, m))
		p->position[1] -= p->v_dir[1] * speed;
}

static void	move_player_right(t_player *p, t_map *m, double speed)
{
	double	new_angle;

	new_angle = p->dir_angle + PI * 0.5;
	if (!inside_a_wall(p->position[0]
			+ cos(new_angle) * speed, p->position[1], m))
		p->position[0] += cos(new_angle) * speed;
	if (!inside_a_wall(p->position[0], p->position[1]
			+ sin(new_angle) * speed, m))
		p->position[1] += sin(new_angle) * speed;
}

static void	move_player_left(t_player *p, t_map *m, double speed)
{
	double	new_angle;

	new_angle = p->dir_angle - PI * 0.5;
	if (!inside_a_wall(p->position[0]
			+ cos(new_angle) * speed, p->position[1], m))
		p->position[0] += cos(new_angle) * speed;
	if (!inside_a_wall(p->position[0], p->position[1]
			+ sin(new_angle) * speed, m))
		p->position[1] += sin(new_angle) * speed;
}

void	move_player(t_player *p, t_map *m, int keysym, double speed)
{
	if (keysym == KEY_W)
		move_player_forward(p, m, speed);
	if (keysym == KEY_S)
		move_player_back(p, m, speed);
	if (keysym == KEY_D)
		move_player_right(p, m, speed);
	if (keysym == KEY_A)
		move_player_left(p, m, speed);
}
