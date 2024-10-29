/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:47:43 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/29 09:45:00 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

bool	init_door_sprite(t_data *data)
{
	t_sprite_slice	slice;

	slice.x = 0;
	slice.y = 0;
	slice.width = 128;
	slice.height = 128;
	if (!data->map.nb_doors)
		return (true);
	data->door_s = new_sprite(data, "./assets/textures/door512x128.xpm");
	if (!data->door_s)
		return (false);
	data->door_s->animated = true;
	ft_lstadd_back(&data->door_s->anim,
		ft_lstnew(ft_slice_sprite(data->door_s, slice, 4, 5)));
	return (true);
}

void	update_doors_anim(t_data *data)
{
	int		i;
	t_door	*door;

	i = -1;
	if (!data->map.nb_doors)
		return ;
	while (++i < (int)data->map.nb_doors)
	{
		door = &((data->map.doors)[i]);
		if (door->status == OPEN || door->status == CLOSE)
			continue ;
		if (door->_tmp_delay++ == door->delay)
		{
			door->_tmp_delay = 0;
			if (door->status == OPENING)
				door->curr_frame++;
			else
				door->curr_frame--;
			if (door->curr_frame == door->nb_frames - 1)
				door->status = OPEN;
			if (door->curr_frame == 0)
				door->status = CLOSE;
		}
	}
}
