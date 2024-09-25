/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:03:40 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/24 17:33:38 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->l_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_color(double dist, int r, int g, int b)
{
	int	color;

	color = ((int)(dist * 255) << 24) | (r << 16) | (g << 8) | b;
	return (color);
}

void	draw_circle(t_img *img, t_point center, int r, int color)
{
	size_t	i;
	size_t	j;
	t_point	p;
	double	dis;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
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
