/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:06:13 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/25 08:58:30 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "parse.h"

int	init_data(t_data *data, char **argv)
{
	data->win = NULL;
	data->img = NULL;
	data->mnmap = NULL;
	init_map(&data->map);
	if (!initialize_map(&data->map, argv[1]))
		return (0);
	data->player.position[0] = data->map.player.position[0];
	data->player.position[1] = data->map.player.position[1];
	data->player.dir_angle = 2 * PI;
	data->player.v_dir[0] = cos(data->player.dir_angle);
	data->player.v_dir[1] = sin(data->player.dir_angle);
	data->player.fov = 30;
	data->player.v_plane[0] = 0;
	data->player.v_plane[1] = 0.66;
	data->win = ft_initmlx();
	if (!data->win)
		return (0);
	data->img = new_img(data->win, M_W, M_H);
	if (!data->img)
		return (0);
	data->mnmap = init_mmap();
	if (!data->mnmap)
		return (0);
	return (1);
}

void	free_data(t_data *data)
{
	free_map(&data->map);
	if (data->img)
	{
		free_img(data->img);
		free(data->img);
	}
	if (data->win)
	{
		free_win(data->win);
		free(data->win);
	}
	if (data->mnmap)
		free(data->mnmap);
}
