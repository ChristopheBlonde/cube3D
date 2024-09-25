/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:47:45 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/25 12:50:08 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	move_player_forward(t_player *p, double size)
{
	p->position[0] += p->v_dir[0] * size;
	p->position[1] += p->v_dir[1] * size;
}

void	move_player_back(t_player *p, double size)
{
	p->position[0] -= p->v_dir[0] * size;
	p->position[1] -= p->v_dir[1] * size;
}

void	move_player_right(t_player *p, double size)
{
	double	new_angle;

	new_angle = p->dir_angle + PI * 0.5;
	p->position[0] += cos(new_angle) * size;
	p->position[1] += sin(new_angle) * size;
}

void	move_player_left(t_player *p, double size)
{
	double	new_angle;

	new_angle = p->dir_angle - PI * 0.5;
	p->position[0] += cos(new_angle) * size;
	p->position[1] += sin(new_angle) * size;
}

void	move_player(t_player *p, int keysym, double size)
{
	if (keysym == XK_w)
		move_player_forward(p, size);
	if (keysym == XK_s)
		move_player_back(p, size);
	if (keysym == XK_d)
		move_player_right(p, size);
	if (keysym == XK_a)
		move_player_left(p, size);
}
