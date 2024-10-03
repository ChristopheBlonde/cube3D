/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:46:25 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/03 14:40:23 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_LINE_H
# define DRAW_LINE_H

# include "data.h"
# include "graph.h"

typedef struct s_data t_data;

typedef struct s_line
{
	double	perp_wall_dist;
	double	line_height;
	double	draw_start;
	double	draw_end;
	int		ceiling_color;
	int		floor_color;
}	t_line;

void    draw_line(t_data *data, int x);
void    pixel_line(t_data *data, int x);
void    init_line(t_data *data);
double  calculate_perp_wall_dist(t_data *data);

# endif
