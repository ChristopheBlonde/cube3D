/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:58:36 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/07 12:45:45 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

void	swap_doors(t_door *door, int a, int b)
{
	t_door	tmp;

	tmp = door[a];
	door[a] = door[b];
	door[b] = tmp;
}

void	curr_dist_door(t_data *data)
{
	double	pos_x;
	double	pos_y;
	double	door_x;
	double	door_y;
	int		i;

	i = -1;
	pos_x = data->player.position[0];
	pos_y = data->player.position[1];
	while (++i < (int)data->map.nb_doors)
	{
		door_x = (double)data->map.doors[i].pos_x;
		door_y = (double)data->map.doors[i].pos_y;
		data->map.doors[i].curr_dist = ((pos_x - door_x) * (pos_x - door_x)
				+ (pos_y - door_y) * (pos_y - door_y));
	}
}

void	sort_door(t_data *data)
{
	int	*index;
	int	i;
	int	j;

	i = -1;
	index = (int *)ft_calloc(data->map.nb_doors, sizeof(int));
	if (!index)
		return ;
	curr_dist_door(data);
	while (++i < (int)data->map.nb_doors)
	{
		j = i;
		while (j < (int)data->map.nb_doors)
		{
			if (data->map.doors[j].curr_dist > data->map.doors[i].curr_dist)
				swap_doors(data->map.doors, i, j);
			j++;
		}
	}
	free(index);
}
