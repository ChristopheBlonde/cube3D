/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mnmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:22:13 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/14 12:13:30 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static bool	bsp(t_point a, t_point b, t_point c, t_point p)
{
	double	v1;
	double	v2;

	v1 = (a.x * (c.y - a.y) + (p.y - a.y) * (c.x - a.x) - p.x * (c.y - a.y))
		/ ((b.y - a.y) * (c.x - a.x) - (b.x - a.x) * (c.y - a.y));
	v2 = (p.y - a.y - v1 * (b.y - a.y)) / (c.y - a.y);
	if (v1 >= 0 && v2 >= 0 && v1 + v2 <= 1)
		return (true);
	return (false);
}

static void	render_player(t_data *data, t_point a, t_point b, t_point c)
{
	double	x;
	t_point	end;
	t_point	start;
	t_point	mid;

	mid = data->mnmap->mnm_mid;
	start = mid;
	start.x = mid.x - data->mnmap->size / 2;
	start.y = mid.y - data->mnmap->size / 2;
	end.x = start.x + data->mnmap->size;
	end.y = start.y + data->mnmap->size;
	x = start.x;
	while (start.y < end.y)
	{
		start.x = x;
		while (start.x < end.x)
		{
			if (bsp(a, b, mid, start) || bsp(mid, b, c, start))
				my_mlx_pixel_put(data->img, (int)start.x, (int)start.y,
					get_color(1, 255, 92, 0));
			start.x += 1;
		}
		start.y += 1;
	}
}

void	init_render_player(t_data *data)
{
	t_point	mid;
	t_point	a;
	t_point	b;
	t_point	c;
	double	half_size;

	half_size = data->mnmap->size / 2;
	mid = data->mnmap->mnm_mid;
	a.x = mid.x - half_size;
	a.y = mid.y + half_size;
	b.x = mid.x;
	b.y = mid.y - half_size;
	c.x = mid.x + half_size;
	c.y = mid.y + half_size;
	render_player(data, a, b, c);
}
