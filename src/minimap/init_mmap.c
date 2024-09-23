/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:23:19 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/23 17:28:48 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

t_minimap	init_mmap(t_win win)
{
	t_minimap map;

	map.width = M_W / 5;
	map.height = M_H / 4;
	map.mid.x = map.width / 2;
	map.mid.y = map.height / 2;
	if (map.width < map.height)
		map.radius = map.width / 2 - 10;
	else
		map.radius = map.height / 2 - 10;
	map.img = new_img(win, map.width, map.height);
	return (map);
}

static bool	is_in_map(t_point p, t_minimap map)
{
	double	dis;

	dis = sqrt((p.x - map.mid.x) * (p.x - map.mid.x)
		+ (p.y - map.mid.y) * (p.y - map.mid.y));
	if (dis >= (double)map.radius - 2)
		return (true);
	return (false);
}

static void	draw_elemmap(t_point p, t_map map, t_minimap mnmap, t_img img)
{
	int x;
	int y;

	x = (int)(p.x - (int)mnmap.width / 2) / 10 + (int)map.player.pos.x;
	y = (int)(p.y - (int)mnmap.radius - 20) / 10  + (int)map.player.pos.y;
	if (x >= 0 && x < (int)map.width && y >= 0 && y < (int)map.height)
	{
		if (map.map[y][x] == '0' || map.map[y][x] == 'N'
			|| map.map[y][x] == 'S' || map.map[y][x] == 'E'
			|| map.map[y][x] == 'W')
			my_mlx_pixel_put(&img, p.x, p.y, get_color(0.1, 80, 216, 215));
		if (map.map[y][x] == '1')
			my_mlx_pixel_put(&img, p.x, p.y, get_color(0.1, 41, 49, 50));
	}
}

void	draw_mnmap(t_minimap mnmap, t_map map, t_img img)
{
	int	x;
	int	y;
	t_point	pos;

	y = 0;
	while (y < mnmap.height)
	{
		x = 0;
		while (x < mnmap.width)
		{
			pos.x = x;
			pos.y = y;
			if (!is_in_map(pos, mnmap))
			{
				draw_elemmap(pos, map, mnmap, img);
			}
			x++;
		}
		y++;
	}
	//draw_player();
}
