/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:00:59 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/24 17:29:41 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	rotate_player(t_player *p, double size)
{
	double	tmp;

	p->dir_angle += size;
	tmp = p->v_dir[0];
	p->v_dir[0] = cos(size) * tmp - sin(size) * p->v_dir[1];
	p->v_dir[1] = sin(size) * tmp + cos(size) * p->v_dir[1];
	tmp = p->v_plane[0];
	p->v_plane[0] = cos(size) * tmp - sin(size) * p->v_plane[1];
	p->v_plane[1] = sin(size) * tmp + cos(size) * p->v_plane[1];
}
