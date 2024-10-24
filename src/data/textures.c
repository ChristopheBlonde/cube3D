/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:56:58 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/24 16:10:21 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static t_img	*init_tex_tab(void)
{
	t_img	*tab;

	tab = (t_img *)ft_calloc(NB_OF_TEX + 1, sizeof(t_img));
	if (!tab)
		return (err_alloc());
	return (tab);
}

static bool	set_texture_img(t_data *data, t_img *texture, char *texture_name)
{
	texture->img_ptr = mlx_xpm_file_to_image(data->win->mlx_ptr,
			texture_name, &texture->width, &texture->height);
	if (!texture->img_ptr)
		return (err_open(texture_name));
	texture->addr = mlx_get_data_addr(texture->img_ptr,
			&texture->bpp, &texture->l_len, &texture->endian);
	texture->win = data->win;
	return (true);
}

bool	init_textures(t_data *data)
{
	t_line	*line;

	line = data->line;
	line->texture = init_tex_tab();
	if (!line->texture)
		return (false);
	if (!set_texture_img(data, &data->line->texture[0], data->map.no))
		return (false);
	if (!set_texture_img(data, &data->line->texture[1], data->map.so))
		return (false);
	if (!set_texture_img(data, &data->line->texture[2], data->map.we))
		return (false);
	if (!set_texture_img(data, &data->line->texture[3], data->map.ea))
		return (false);
	if (!set_texture_img(data, &data->line->texture[4],
			"assets/textures/wood1.xpm"))
		return (false);
	if (!set_texture_img(data, &data->line->texture[5],
			"assets/textures/wood4.xpm"))
		return (false);
	if (!set_texture_img(data, &data->line->texture[6],
			"./assets/textures/Door00.xpm"))
		return (false);
	return (true);
}

void	free_textures(t_data *data)
{
	int		i;
	t_img	current;

	i = 0;
	if (data->line->texture)
	{
		while (i < NB_OF_TEX)
		{
			current = data->line->texture[i];
			if (current.win->mlx_ptr && current.img_ptr)
				mlx_destroy_image(current.win->mlx_ptr, current.img_ptr);
			i++;
		}
	}
	free(data->line->texture);
}
