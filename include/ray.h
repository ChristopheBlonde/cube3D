/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:43:12 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/12 11:59:59 by cblonde          ###   ########.fr       */
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
	double	dalpha;
	t_dir	side;
}	t_ray;

int		raycasting(t_data *data);
bool	checkdoor(t_data *data);
void	init_zdoordist(t_data *data);
void	render_doors(t_data *data);
void	init_ray(t_data *data, int x) __attribute__((always_inline));
void	calculating_initial_side_dist(t_data *data)
		__attribute__((always_inline));
void	calculating_ray_size(t_data *data, int x,
			bool doorloop, t_door *door[2]) __attribute__((always_inline));
double	get_alpha(double dist) __attribute__((always_inline));

#endif
