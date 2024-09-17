/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:31:15 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/17 12:43:30 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "libft.h"
# include "point.h"

typedef enum	e_direction
{
	NONE,
	NORTH,
	SOUTH,
	EAST,
	WEST,
} t_dir;

typedef struct	s_player
{
	t_dir	dir;
	t_point	pos;
} t_player;

t_dir	get_direction(char c);

#endif
