/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:09:37 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/08 11:49:03 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

t_sprite	*new_sprite(t_data *data, char *file)
{
	t_sprite	*sprite;

	sprite = NULL;
	sprite = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	if (!sprite)
		return (sprite);
	sprite->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!sprite->img)
	{
		free_sprite(sprite);
		return (NULL);
	}
	sprite->img->img_ptr = mlx_xpm_file_to_image(data->win->mlx_ptr, file,
			&sprite->width, &sprite->height);
	sprite->img->win = data->win;
	if (!sprite->img->img_ptr)
	{
		free_sprite(sprite);
		return (NULL);
	}
	else
		sprite->img->addr = mlx_get_data_addr(sprite->img->img_ptr,
				&sprite->img->bpp, &sprite->img->l_len, &sprite->img->endian);
	return (sprite);
}

void	free_sprite(t_sprite *sprite)
{
	if (!sprite)
		return ;
	if (sprite->img && sprite->img->img_ptr)
		free_img(sprite->img);
	sprite->img->img_ptr = NULL;
	if (sprite->img)
		free(sprite->img);
	sprite->img = NULL;
	free(sprite);
}

bool	init_arr_sprites(t_data *data)
{
	data->arr_s = (t_sprite **)ft_calloc(2, sizeof(t_sprite *));
	if (!data->arr_s)
		return (false);
	return (true);
}

void	free_arr_sprites(t_sprite **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free_sprite(arr[i]);
		arr[i] = NULL;
		i++;
	}
}
