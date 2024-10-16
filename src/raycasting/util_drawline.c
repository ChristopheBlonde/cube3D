/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_drawline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:30:26 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/16 11:31:20 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_line.h"

double	calculate_perp_wall_dist(t_data *data)
{
	if (data->ray->side == EAST || data->ray->side == WEST)
		return (data->ray->side_dist_x - data->ray->delta_dist_x);
	else
		return (data->ray->side_dist_y - data->ray->delta_dist_y);
}
