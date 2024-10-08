/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:31:15 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/08 11:58:32 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "libft.h"
# include "point.h"
# include "math.h"
# include <X11/keysym.h>

# define PI M_PI 

typedef enum e_direction
{
	NONE,
	NORTH,
	SOUTH,
	EAST,
	WEST,
}	t_dir;

typedef struct s_player
{
	t_dir	dir;
	t_point	pos;
	double	position[2];
	double	dir_angle;
	double	v_dir[2];
	double	v_plane[2];
	int		fov;
}	t_player;

t_dir	get_direction(char c);
void	move_player(t_player *p, int keysym, double size);
void	rotate_player(t_player *p, double size);

#endif
