/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:19:52 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/08 14:12:19 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

void	render_sprite(t_data *data)
{
	int		i;
	double	inv_det;
	double	trf_x;
	double	trf_y;
	int		s_sc_x;

	i = 0;
	while (data->arr_s[i])
	{
		data->arr_s[i]->cam_x = data->arr_s[i]->pos_x - data->player.position[0];
		data->arr_s[i]->cam_y = data->arr_s[i]->pos_y - data->player.position[1];

		inv_det = 1.0 / (data->player.v_plane[0] * data->player.v_dir[1]
				- data->player.v_dir[0] * data->player.v_plane[1]);

		trf_x = inv_det * (data->player.v_dir[1] * data->arr_s[i]->cam_x
				- data->player.v_dir[0] * data->arr_s[i]->cam_y);

		trf_y = inv_det * (-data->player.v_plane[1] * data->arr_s[i]->cam_x
				+ data->player.v_plane[0] * data->arr_s[i]->cam_y);

		s_sc_x = (int)((M_W / 2) * (1 + trf_x / trf_y));

		int s_h = abs(((int)(M_H / trf_y)));

		int drawstart_y = -s_h / 2 + M_H / 2;
		if (drawstart_y < 0)
			drawstart_y = 0;

		int drawend_y = s_h / 2 + M_H / 2;
		if (drawend_y >= M_H)
			drawend_y = M_H - 1;

		int s_w = abs(((int)(M_H / trf_y)));

		int drawstart_x = -s_w / 2 + s_sc_x;
		if (drawstart_x < 0)
			drawstart_x = 0;

		int drawend_x = s_w / 2 + s_sc_x;
		if (drawend_x >= M_W)
			drawend_x = M_W - 1;
		int x = drawstart_x;
		while (x < drawend_x)
		{
			int y = drawstart_y;
			while (y < drawend_y)
			{
// if(transformY > 0 && stripe > 0 && stripe < w && transformY < ZBuffer[stripe])
				if (trf_y > 0 && x > 0 && x < M_W && trf_y < data->zdist[x])
					my_mlx_pixel_put(data->img, x, y, 0xFFFF0000);
			}
			x++;
		}
		i++;
	}
}
