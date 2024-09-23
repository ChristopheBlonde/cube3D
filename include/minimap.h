/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 08:27:26 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/23 17:28:51 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "graph.h"
# include "map.h"

typedef struct	s_minimap
{
	t_point	mid;
	int		radius;
	int		width;
	int		height;
	t_img	img;
}	t_minimap;

t_minimap	init_mmap(t_win win);
void		draw_mnmap(t_minimap mnmap, t_map map, t_img img);

#endif
