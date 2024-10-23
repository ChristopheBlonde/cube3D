/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:56:58 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/23 16:40:46 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_img	*init_tex_tab(void)
{
	t_img	*tab;

	tab = malloc(sizeof(t_img) * NB_OF_TEX);
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
			"./assets/textures/Door.xpm"))
		return (false);
	return (true);
}
