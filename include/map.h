/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:40:37 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/28 12:29:36 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include "libft.h"
# include "player.h"

typedef enum e_door_status
{
	CLOSE,
	CLOSING,
	OPEN,
	OPENING,
}	t_dstatus;

typedef enum e_door_derection
{
	NODIR,
	NS,
	EW,
}	t_d_dir;

typedef struct s_door
{
	t_d_dir		dir;
	t_dstatus	status;
	int			pos_x;
	int			pos_y;
	double		perp_door_dist;
}	t_door;

typedef struct s_map
{
	char		**map;
	size_t		height;
	size_t		width;
	size_t		floor[3];
	size_t		ceiling[3];
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	size_t		curr_sprite;
	size_t		sprite_nb;
	char		**sprites;
	t_player	player;
	size_t		nb_doors;
	t_door		*doors;
}	t_map;

void	init_map(t_map *map);
void	free_map(t_map *map);

#endif
