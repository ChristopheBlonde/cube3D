/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:40:37 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/16 09:25:34 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct	s_map
{
	char	**map;
	int		height;
	int		width;
	int		floor[3];
	int		ceiling[3];
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
} t_map;

void	init_map(t_map *map);
void	free_map(t_map *map);
#endif
