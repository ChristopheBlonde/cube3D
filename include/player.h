/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:31:15 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/15 11:58:10 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "libft.h"
# include "point.h"
# include "math.h"
# include <X11/keysym.h>

# define PI M_PI
# define KEY_NB 6

typedef struct	s_data	t_data;
typedef struct	s_map	t_map;

typedef enum e_direction
{
	NONE,
	NORTH,
	SOUTH,
	EAST,
	WEST,
}	t_dir;

typedef enum	e_keyboard
{
	KEY_W,
	KEY_A,
	KEY_S,
	KEY_D,
	KEY_LEFT,
	KEY_RIGHT,
} t_keyboard;

typedef struct	s_player
{
	t_dir	dir;
	t_point	pos;
	double	position[2];
	double	dir_angle;
	double	v_dir[2];
	double	v_plane[2];
	int		keyboard[KEY_NB];
	double	offset_y;
}	t_player;

t_dir	get_direction(char c);
int		inside_a_wall(int x, int y, t_map *m);
void	move_player(t_player *p, t_map *m, int keysym, double speed);
void	rotate_player(t_player *p, double speed);
int		handle_input(t_data *data);

#endif
