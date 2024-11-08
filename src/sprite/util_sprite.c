/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:09:37 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/08 12:01:52 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

static void	init_new_sprite(t_data *data, t_sprite *sprite)
{
	sprite->img->win = data->win;
	sprite->width = sprite->img->width;
	sprite->height = sprite->img->height;
	sprite->img->addr = mlx_get_data_addr(sprite->img->img_ptr,
			&sprite->img->bpp, &sprite->img->l_len, &sprite->img->endian);
}

t_sprite	*new_sprite(t_data *data, char *file)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	if (!sprite)
		return (NULL);
	sprite->anim = NULL;
	sprite->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!sprite->img)
	{
		free_sprite(sprite);
		return (NULL);
	}
	sprite->img->img_ptr = mlx_xpm_file_to_image(data->win->mlx_ptr, file,
			(int *)&sprite->img->width, (int *)&sprite->img->height);
	sprite->img->win = data->win;
	if (!sprite->img->img_ptr)
	{
		free_sprite(sprite);
		return (NULL);
	}
	init_new_sprite(data, sprite);
	return (sprite);
}

void	free_sprite(t_sprite *sprite)
{
	t_list	*frames;
	t_anim	*anim;
	t_list	*lst_anim;

	if (!sprite)
		return ;
	if (sprite->img && sprite->img->img_ptr)
		free_img(sprite->img);
	sprite->img = NULL;
	if (sprite->anim)
	{
		lst_anim = (t_list *)sprite->anim;
		while (lst_anim)
		{
			anim = (t_anim *)(lst_anim)->content;
			frames = (t_list *)anim->frames;
			ft_lstclear(&frames, free_img);
			lst_anim = lst_anim->next;
		}
		ft_lstclear(&sprite->anim, free);
		sprite->anim = NULL;
	}
	free(sprite);
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
	free(arr);
}

t_img	*get_current_img(t_sprite *sprite)
{
	t_img	*img;
	t_list	*lst_anim;
	t_anim	*anim;
	t_list	*frames;
	int		i;

	i = 0;
	lst_anim = (t_list *)sprite->anim;
	if (sprite->type == PLAYER)
	{
		while (i != sprite->lst_nb)
		{
			lst_anim = lst_anim->next;
			i++;
		}
	}
	anim = (t_anim *)lst_anim->content;
	frames = (t_list *)anim->frames;
	img = (t_img *)ft_lstget(frames, anim->current_frame_num)->content;
	return (img);
}
