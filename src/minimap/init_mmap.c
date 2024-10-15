/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:23:19 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/14 12:26:45 by cblonde          ###   ########.fr       */
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

static void	rotation_map(t_data *data, double *x, double *y, double angle)
{
	double	tmp_x;
	double	tmp_y;
	double	x_cos;
	double	x_sin;

	x_cos = cos(angle);
	x_sin = sin(angle);
	tmp_x = (*x * x_cos) - (*y * x_sin);
	tmp_y = (*x * x_sin) + (*y * x_cos);
	*x = tmp_x + data->player.position[0];
	*y = tmp_y + data->player.position[1];
}

static void	draw_elemmap(t_data *data, t_point p)
{
	double		x;
	double		y;
	t_map		map;
	t_minimap	*mnmap;
	double		angle;

	map = data->map;
	mnmap = data->mnmap;
	x = (p.x - mnmap->mnm_mid.x) / mnmap->size;
	y = (p.y - mnmap->mnm_mid.y) / mnmap->size;
	angle = atan2(data->player.v_dir[1], data->player.v_dir[0]) + PI / 2;
	rotation_map(data, &x, &y, angle);
	if ((int)x >= 0 && (int)x < (int)map.width
		&& (int)y >= 0 && (int)y < (int)map.height
		&& (int)x < (int)ft_strlen(map.map[(int)y]))
	{
		if (map.map[(int)y][(int)x] == '0')
			my_mlx_pixel_put(data->img,
				p.x, p.y, alpha(0.5, ft_get_pixel_img(*data->img, p.x, p.y),
					get_color(1, 80, 216, 215)));
		if (map.map[(int)y][(int)x] == '1')
			my_mlx_pixel_put(data->img,
				p.x, p.y, alpha(0.5, ft_get_pixel_img(*data->img, p.x, p.y),
					get_color(1, 41, 49, 50)));
	}
}

void	draw_mnmap(t_data *data)
{
	int		x;
	int		y;
	t_point	pos;

	draw_circle(data->img, data->mnmap->mid, data->mnmap->radius,
		get_color(1, M_RED, M_GREEN, M_BLUE));
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
