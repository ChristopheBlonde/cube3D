/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:40:37 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/30 08:40:26 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include "libft.h"
# include "player.h"

typedef struct	s_map
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
	t_player	player;
} t_map;

void	init_map(t_map *map);
void	free_map(t_map *map);

#endif
