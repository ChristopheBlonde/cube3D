/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:43:12 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/23 16:10:08 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "draw_line.h" 
# include "player.h"
# include "graph.h"

typedef struct s_data	t_data;

typedef struct s_ray
{
	double	ray_dir[2];
	double	camera_x;
	int		map[2];
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	t_dir	side;
	t_door	*door;
}	t_ray;

int		raycasting(t_data *data);
bool	checkdoor(t_data *data);
t_door	*get_door(t_data *data, int x, int y);
void	draw_doors(t_data *data, int x);
double	calculate_perp_door_dist(t_data *data);

#endif
