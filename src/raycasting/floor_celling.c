#include "cube.h"

void    init_struct_floor(t_data *data, int y)
{
	data->floor_c->ray_dir_x0 = data->player.v_dir[0] - data->player.v_plane[0];
	data->floor_c->ray_dir_y0 = data->player.v_dir[1] - data->player.v_plane[1];
	data->floor_c->ray_dir_x1 = data->player.v_dir[0] + data->player.v_plane[0];
	data->floor_c->ray_dir_y1 = data->player.v_dir[1] + data->player.v_plane[1];

	data->floor_c->row_dist_floor = (0.5 * M_H) / (y - M_H * 0.5 - data->player.offset_y);
	data->floor_c->row_dist_celling = (0.5 * M_H) / (y - M_H * 0.5 + data->player.offset_y);
	
	data->floor_c->floor_step_x = data->floor_c->row_dist_floor * (data->floor_c->ray_dir_x1 - data->floor_c->ray_dir_x0) / M_W;
	data->floor_c->floor_step_y = data->floor_c->row_dist_floor * (data->floor_c->ray_dir_y1 - data->floor_c->ray_dir_y0) / M_W;
	data->floor_c->floor_x = data->player.position[0] + data->floor_c->row_dist_floor * data->floor_c->ray_dir_x0;
	data->floor_c->floor_y = data->player.position[1] + data->floor_c->row_dist_floor * data->floor_c->ray_dir_y0;

	data->floor_c->celling_step_x = data->floor_c->row_dist_celling * (data->floor_c->ray_dir_x1 - data->floor_c->ray_dir_x0) / M_W;
	data->floor_c->celling_step_y = data->floor_c->row_dist_celling * (data->floor_c->ray_dir_y1 - data->floor_c->ray_dir_y0) / M_W;
	data->floor_c->celling_x = data->player.position[0] + data->floor_c->row_dist_celling * data->floor_c->ray_dir_x0;
	data->floor_c->celling_y = data->player.position[1] + data->floor_c->row_dist_celling * data->floor_c->ray_dir_y0;
}

void	init_tex_point(t_data *data, t_point *tex_floor, t_point *tex_celling)
{
	tex_floor->x = (int)(data->line->texture[4].width * (data->floor_c->floor_x - (int)data->floor_c->floor_x)) & (data->line->texture[4].width - 1);
	tex_floor->y = (int)(data->line->texture[4].height * (data->floor_c->floor_y - (int)data->floor_c->floor_y)) & (data->line->texture[4].height - 1);
	tex_celling->x = (int)(data->line->texture[5].width * (data->floor_c->celling_x - (int)data->floor_c->celling_x)) & (data->line->texture[5].width - 1);
	tex_celling->y = (int)(data->line->texture[5].height * (data->floor_c->celling_y - (int)data->floor_c->celling_y)) & (data->line->texture[5].height - 1);
}

void	draw_floor_celling_tmp(t_data *data, int x, int y)
{
	t_point tex_floor;
	t_point tex_celling;
	int		color[2];

	init_tex_point(data, &tex_floor, &tex_celling);
	data->floor_c->floor_x += data->floor_c->floor_step_x;
	data->floor_c->floor_y += data->floor_c->floor_step_y;
	data->floor_c->celling_x += data->floor_c->celling_step_x;
	data->floor_c->celling_y += data->floor_c->celling_step_y;
	color[0] = ft_get_pixel_img(data->line->texture[4], tex_floor.x, tex_floor.y);
	color[1] = ft_get_pixel_img(data->line->texture[5], tex_celling.x, tex_celling.y);
	my_mlx_pixel_put(data->img, x, y, color[0]);
	my_mlx_pixel_put(data->img, x, M_H - y - 1, color[1]);
}

void	draw_floor_celling(t_data *data)
{
	t_floor_celling	floor_c;
	int				y;
	int				x;

	y = 0;
	data->floor_c = &floor_c;
	while (y < M_H)
	{
		init_struct_floor(data, y);
		x = 0;
		while (x < M_W)
		{
			draw_floor_celling_tmp(data, x, y);
			x++;
		}
		y++;
	}
}