/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 08:27:26 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/16 15:31:02 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "map.h"
# include "graph.h"
# include "data.h"

typedef struct s_data	t_data;

typedef struct s_minimap
{
	bool	minimap;
	t_point	mid;
	t_point	mnm_mid;
	double	size;
	int		radius;
	int		width;
	int		height;
}	t_minimap;

t_minimap	*init_mmap(void);
void		draw_mnmap(t_data *data);
void		init_render_player(t_data *data);

#endif
