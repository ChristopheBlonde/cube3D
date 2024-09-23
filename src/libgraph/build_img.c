/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:48:05 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/23 08:38:27 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_img	new_img(t_win win, int w, int h)
{
	t_img	img;

	img.win = win;
	img.img_ptr = mlx_new_image(win.mlx_ptr, w, h);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp,
		&img.l_len, &img.endian);
	img.width = w;
	img.height = h;
	return (img);
}
