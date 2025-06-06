/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:46:25 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/12 11:35:06 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_LINE_H
# define DRAW_LINE_H

# include "data.h"
# include "graph.h"
# define NB_OF_TEX 6

typedef struct s_data	t_data;
typedef struct s_img	t_img;

typedef struct s_line
{
	double	perp_wall_dist;
	double	line_height;
	double	wall_x;
	double	draw_start;
	double	draw_end;
	int		ceiling_color;
	int		floor_color;
	t_img	*texture;
	int		tex_num;
	int		tex_x;
	int		tex_y;
	double	step;
	double	floor_x_wall;
	double	floor_y_wall;
	double	dist_wall;
	double	dist_player;
	double	current_dist;
}	t_line;

void	draw_line(t_data *data, int x) __attribute__((always_inline));
double	calculate_perp_wall_dist(t_data *data) __attribute__((always_inline));
void	draw_floor_celling(t_data *data) __attribute__((always_inline));
t_door	*get_door(t_data *data, int x, int y) __attribute__((always_inline));
double	calculate_perp_door_dist(t_data *data) __attribute__((always_inline));
void	draw_doors(t_data *data, int x) __attribute__((always_inline));

#endif
