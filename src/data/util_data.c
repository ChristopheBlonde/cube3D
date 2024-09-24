/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:06:13 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/24 11:48:52 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "parse.h"

int	init_data(t_data *data, char **argv)
{
	init_map(&data->map);
	if (!initialize_map(&data->map, argv[1]))
		return (0);
	data->win = ft_initmlx();
	if (!data->win.mlx_ptr || !data->win.win_ptr)
		return (0);
	data->img = new_img(data->win, M_W, M_H);
	if (!data->img.img_ptr)
		return (0);
	data->mnmap = init_mmap();
	return (1);
}

void	free_data(t_data *data)
{
		free_map(&data->map);
		free_img(&data->img);
		free_win(&data->win);
		if (data->mnmap)
			free(data->mnmap);
}
