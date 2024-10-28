/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:47:43 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/28 09:19:17 by cblonde          ###   ########.fr       */
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
