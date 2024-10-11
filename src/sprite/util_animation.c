/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:40:28 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/11 12:47:49 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

void	add_frame(t_anim *anim, t_sprite *sprite, t_sprite_slice slice)
{
	t_img	*frame;
	int		i;
	int		j;

	i = 0;
	frame = new_img(sprite->img->win, slice.width, slice.height);
	while (i < slice.width)
	{
		j = 0;
		while (j < slice.height)
		{
			my_mlx_pixel_put(frame, j, i, ft_get_pixel_img(
					*sprite->img, slice.x + j, slice.y + i));
			j++;
		}
		i++;
	}
	ft_lstadd_back(&anim->frames, ft_lstnew(frame));
}

static void	ft_initialize_animation(t_anim *anim,
			t_sprite_slice slice, int delay)
{
	anim->frames = NULL;
	anim->width = slice.width;
	anim->height = slice.height;
	anim->delay = delay;
	anim->_tmp_delay = delay - 1;
	anim->current_frame_num = 0;
	anim->last_updated = 0;
	anim->frame_count = 0;
}

t_anim	*ft_slice_sprite(t_sprite *sprite, t_sprite_slice slice,
				int frames, int delay)
{
	int		i;
	t_anim	*animation;

	i = 0;
	animation = (t_anim *)ft_calloc(1, sizeof(t_anim));
	if (!animation)
		return (NULL);
	ft_initialize_animation(animation, slice, delay);
	while (i < frames)
	{
		add_frame(animation, sprite, slice);
		slice.x += slice.width;
		if (slice.x >= sprite->width)
		{
			slice.x = 0;
			slice.y += slice.height;
		}
		i++;
	}
	return (animation);
}

void	init_sprite(t_sprite *sprite, double x, double y, bool animated)
{
	t_sprite_slice	s;

	s.x = 0;
	s.y = 0;
	s.width = 64;
	s.height = 64;
	sprite->pos_x = x;
	sprite->pos_y = y;
	sprite->render.u_div = 3;
	sprite->render.v_div = 3;
	sprite->render.v_move = (sprite->height + 5) * sprite->render.v_div;
	sprite->anim = NULL;
	if (!animated)
		sprite->animated = false;
	else
	{
		sprite->animated = true;
		ft_lstadd_back(&sprite->anim,
			ft_lstnew(ft_slice_sprite(sprite, s, 4, 1)));
		sprite->render.v_move *= 2;
	}
}
