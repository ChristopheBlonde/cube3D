/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:28:17 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/30 10:54:26 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "map.h"
# include "minimap.h"
# include "graph.h"
# include "mlx.h"
# include "player.h"
# include "ray.h"
# include "draw_line.h"

typedef struct	s_minimap t_minimap;
typedef struct	s_img t_img;
typedef struct	s_win t_win;
typedef struct	s_ray t_ray;
typedef struct	s_line t_line;

typedef struct	s_data
{
	t_win		*win;
	t_img		*img;
	t_map		map;
	t_minimap	*mnmap;
	t_player	player;
	t_ray		*ray;
	t_line		*line;
}	t_data;

int		init_data(t_data *data, char **argv);
void	free_data(t_data *data);
void	init_textures(t_data *data);

#endif
