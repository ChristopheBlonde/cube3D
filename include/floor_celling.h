/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_celling.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:48:25 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/29 12:48:29 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_CELLING_H
# define FLOOR_CELLING_H

typedef struct s_floor_celling
{
	int		is_floor;
	double	ray_dir_x0;
	double	ray_dir_y0;
	double	ray_dir_x1;
	double	ray_dir_y1;
	int		p;
	double	cam_z;
	double	pos_z;
	double	row_dist;
	double	floor_step_x;
	double	floor_step_y;
	double	floor_x;
	double	floor_y;
}	t_floor_celling;

#endif
