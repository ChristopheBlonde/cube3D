/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:23:19 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/25 16:39:59 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

t_minimap	*init_mmap(void)
{
	t_minimap	*map;

	map = (t_minimap *)ft_calloc(1, sizeof(t_minimap));
	if (!map)
		return (NULL);
	map->width = M_W / 5;
	map->height = M_H / 4;
	map->mid.x = map->width / 2;
	map->mid.y = map->height / 2;
	map->size = 10;
		map->mnm_mid.x = map->width / 2;
		map->mnm_mid.y = map->height / 2;
	if (map->width < map->height)
		map->radius = map->width / 2 - 10;
	else
		map->radius = map->height / 2 - 10;
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

static void	rotation_map(t_data *data, int *x, int *y, double acos_asin[2])
{
	double		tmp_x;
	double		tmp_y;

	tmp_x = *x * acos_asin[0] - *y * acos_asin[1];
	tmp_y = *x * acos_asin[1] - *y * acos_asin[0];
	*x = (int)(tmp_x + data->player.position[0]);
	*y = (int)(tmp_y + data->player.position[1]);
}

static void	draw_elemmap(t_data *data, t_point p)
{
	int			x;
	int			y;
	t_map		map;
	t_minimap	*mnmap;
	double		angle;

	map = data->map;
	mnmap = data->mnmap;
	x = (int)((p.x - mnmap->mnm_mid.x) / mnmap->size);
	y = (int)((p.y - mnmap->mnm_mid.y) / mnmap->size);
	angle = atan2(data->player.v_dir[0], data->player.v_dir[1]) + PI / 2;
	rotation_map(data, &x, &y, (double [2]){cos(angle), sin(angle)});
	if (x >= 0 && x < (int)map.width && y >= 0 && y < (int)map.height
		&& x < (int)ft_strlen(map.map[y]))
	{
		if (map.map[y][x] == '0')
			my_mlx_pixel_put(data->img,
				p.x, p.y, get_color(0.1, 80, 216, 215));
		if (map.map[y][x] == '1')
			my_mlx_pixel_put(data->img,
				p.x, p.y, get_color(0.1, 41, 49, 50));
	}
}

static void	cleanMap(t_data *data)
{
	int		x;
	int		y;
	t_point	pos;

	y = 0;
	while (y < data->mnmap->height)
	{
		x = 0;
		while (x < data->mnmap->width)
		{
			pos.x = x;
			pos.y = y;
			if (!is_in_map(pos, *data->mnmap))
			{
				my_mlx_pixel_put(data->img, x, y, 0x00000000);
			}
			x++;
		}
		y++;
	}
}

void	draw_mnmap(t_data *data)
{
	int		x;
	int		y;
	t_point	pos;

	draw_circle(data->img, data->mnmap->mid, data->mnmap->radius,
		get_color(1, M_RED, M_GREEN, M_BLUE));
	cleanMap(data);
	y = 0;
	while (y < data->mnmap->height)
	{
		x = 0;
		while (x < data->mnmap->width)
		{
			pos.x = x;
			pos.y = y;
			if (!is_in_map(pos, *data->mnmap))
			{
				draw_elemmap(data, pos);
			}
			x++;
		}
		y++;
	}
	init_render_player(data);
}
