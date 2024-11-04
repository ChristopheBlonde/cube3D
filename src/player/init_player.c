/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 08:14:51 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/04 16:33:33 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	**walk_files_name(void)
{
	int		fd;
	char	*tmp;
	char	**arr;

	fd = open("./assets/files/walk_orc.txt", 00);
	if (fd < 0)
	{
		perror("init files assets");
		return (NULL);
	}
	tmp = ft_get_next_line(fd);
	if (!tmp)
		return (NULL);
	tmp[ft_strlen(tmp) - 1] = '\0';
	arr = ft_split(tmp, ' ');
	return (arr);
}

void	finish_move000(t_data *data)
{
	t_sprite	*sprite;
	t_list		*lst;
	t_anim		*anim;

	sprite = data->player.player_s;
	lst = sprite->anim;
	anim = lst->content;
	lst = anim->frames;
	if (!data->player.keyboard[KEY_W] && anim->current_frame_num != 14)
	{
		anim->_tmp_delay = 0;
		if (anim->current_frame_num < 14 && anim->current_frame_num > 4)
		{
			anim->current_frame_num++;
			anim->current_frame_num %= ft_lstsize(lst);
		}
		else
		{
			if (anim->current_frame_num == 0)
				anim->current_frame_num = 19;
			else
				anim->current_frame_num--;
		}
	}
}

static void	init_player_img(t_sprite *sprite)
{
	t_list	*lst_anim;
	t_anim	*anim;

	sprite->animated = true;
	sprite->render.u_div = 1;
	sprite->render.v_div = 1;
	sprite->render.v_move = 340;
	sprite->type = PLAYER;
	sprite->lst_nb = 0;
	lst_anim = sprite->anim;
	anim = lst_anim->content;
	anim->current_frame_num = 14;
}

bool	init_player_sprite(t_data *data)
{
	t_sprite		*sprite;
	t_sprite_slice	slice;
	char			**files;
	t_sprite		*tmp_s;
	int				i;

	i = 0;
	files = walk_files_name();
	if (!files)
		return (false);
	sprite = new_sprite(data, files[0]);
	if (!sprite)
		return (false);
	slice.x = 0;
	slice.y = 0;
	slice.width = 320;
	slice.height = 320;
	while (files[i])
	{
		if (i == 0)
			tmp_s = sprite;
		else
			tmp_s = new_sprite(data, files[i]);
		ft_lstadd_back(&sprite->anim,
				ft_lstnew(ft_slice_sprite(tmp_s, slice, 20, 1)));
		if (i != 0)
			free_sprite(tmp_s);
		i++;
	}
	ft_free_array((void **)files);
	init_player_img(sprite);
	data->player.player_s = sprite;
	data->arr_s[data->map.sprite_nb] = sprite;
	update_player_pos(data);
	return (true);
}

void	update_player_pos(t_data *data)
{
	data->player.player_s->pos_x
		= data->player.position[0] + data->player.v_dir[0];
	data->player.player_s->pos_y
		= data->player.position[1] + data->player.v_dir[1];
}
