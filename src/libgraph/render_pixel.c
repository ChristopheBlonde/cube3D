/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:03:40 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/02 08:54:27 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->l_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_get_pixel_img(t_img img, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	return (*(unsigned int *)(img.addr
		+ (y * img.l_len) + (x * img.bpp / 8)));
}

void	put_pixel_win(t_data *data, int x, int y, int color)
{
	if (color == (int)0xFF000000)
		return ;
	my_mlx_pixel_put(data->img, x, y, color);
}

void	copy_img_to_win(t_data *data, t_sprite *sprite, int x, int y)
{
	int	w;
	int	h;

	h = 0;
	while (h < sprite->height)
	{
		w = 0;
		while (w < sprite->width)
		{
			put_pixel_win(data, w + x, h + y,
				ft_get_pixel_img(*sprite->img, w, h));
			w++;
		}
		h++;
	}
}

void	draw_circle(t_img *img, t_point center, int r, int color)
{
	size_t	i;
	size_t	j;
	t_point	p;
	double	dis;

	i = 0;
	while (i < (size_t)img->height)
	{
		j = 0;
		while (j < (size_t)img->width)
		{
			p.x = j;
			p.y = i;
			dis = sqrt((p.x - center.x) * (p.x - center.x)
					+ (p.y - center.y) * (p.y - center.y));
			if (dis <= (double)r && dis > (double)(r - 2))
				my_mlx_pixel_put(img, p.x, p.y, color);
			j++;
		}
		i++;
	}
}
