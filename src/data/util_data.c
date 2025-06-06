/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:06:13 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/26 09:55:53 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static void	init_dir_angle(t_data *data)
{
	data->player.dir = data->map.player.dir;
	if (data->player.dir == NORTH)
	{
		data->player.dir_angle = PI / 2 + PI;
		data->player.v_plane[0] = 0.66;
		data->player.v_plane[1] = 0;
	}
	if (data->player.dir == SOUTH)
	{
		data->player.dir_angle = PI / 2;
		data->player.v_plane[0] = -0.66;
		data->player.v_plane[1] = 0;
	}
	if (data->player.dir == EAST)
	{
		data->player.dir_angle = 2 * PI;
		data->player.v_plane[0] = 0;
		data->player.v_plane[1] = 0.66;
	}
	if (data->player.dir == WEST)
	{
		data->player.dir_angle = PI;
		data->player.v_plane[0] = 0;
		data->player.v_plane[1] = -0.66;
	}
}

static void	init_t_player(t_data *data)
{
	ft_bzero(&data->player.keyboard, KEY_NB * sizeof(int));
	data->player.position[0] = data->map.player.position[0] + 0.5;
	data->player.position[1] = data->map.player.position[1] + 0.5;
	init_dir_angle(data);
	data->player.v_dir[0] = cos(data->player.dir_angle);
	data->player.v_dir[1] = sin(data->player.dir_angle);
	data->player.offset_y = 0.0;
	data->player.active = false;
}

int	init_data_allocations(t_data *data)
{
	data->line = (t_line *)ft_calloc(1, sizeof(t_line));
	if (!data->line)
		return (0);
	data->line->texture = NULL;
	data->ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
	if (!data->ray)
		return (0);
	if (!init_arr_sprites(data))
		return (0);
	if (ft_arrlen((void **)data->arr_s) != data->map.sprite_nb)
		return (err_sprite(4, NULL));
	if (!init_textures(data))
		return (0);
	if (!init_door_sprite(data))
		return (0);
	return (1);
}

int	init_data(t_data *data, char **argv)
{
	init_data_var(data);
	init_map(&data->map);
	if (!initialize_map(&data->map, argv[1]))
		return (0);
	init_t_player(data);
	data->win = ft_initmlx();
	if (!data->win)
		return (0);
	data->img = new_img(data->win, M_W, M_H);
	if (!data->img)
		return (0);
	data->mnmap = init_mmap();
	if (!data->mnmap)
		return (0);
	if (!init_data_allocations(data))
		return (0);
	return (1);
}

void	free_data(t_data *data)
{
	free_map(&data->map);
	if (data->img)
		free_img(data->img);
	if (data->arr_s)
		free_arr_sprites(data->arr_s);
	if (data->line)
	{
		if (data->line->texture)
			free_textures(data);
		free(data->line);
	}
	if (data->map.nb_doors > 0)
		free_sprite(data->door_s);
	if (data->win)
	{
		free_win(data->win);
		free(data->win);
	}
	if (data->mnmap)
		free(data->mnmap);
	if (data->ray)
		free(data->ray);
}
