#include "cube.h"

void	define_side_floor_tmp(t_data *data, int x)
{
	if ((data->ray->side == EAST || data->ray->side == WEST) && data->ray->ray_dir[0] > 0)
	{
		data->line->floor_x_wall = data->ray->map[0];
		data->line->floor_y_wall = data->ray->map[1] + data->line->wall_x;
	}
	else if ((data->ray->side == EAST || data->ray->side == WEST) && data->ray->ray_dir[0] < 0)
	{
		data->line->floor_x_wall = data->ray->map[0] + 1.0;
		data->line->floor_y_wall = data->ray->map[1] + data->line->wall_x;
	}
	else if ((data->ray->side == NORTH || data->ray->side == SOUTH) && data->ray->ray_dir[1] > 0)
	{
		data->line->floor_x_wall = data->ray->map[0] + data->line->wall_x;
		data->line->floor_y_wall = data->ray->map[1];
	}
	else if ((data->ray->side == NORTH  || data->ray->side == SOUTH) && data->ray->ray_dir[1] < 0)
	{
		data->line->floor_x_wall = data->ray->map[0] + data->line->wall_x;
		data->line->floor_y_wall = data->ray->map[1] + 1.0;
	}
}

void	define_side_floor(t_data *data, int x)
{
	if ((data->ray->side == EAST || data->ray->side == WEST) && data->ray->ray_dir[0] > 0)
	{
		data->line->floor_x_wall = data->ray->map[0];
		data->line->floor_y_wall = data->ray->map[1] + data->line->wall_x;
	}
	else if ((data->ray->side == EAST || data->ray->side == WEST) && data->ray->ray_dir[0] < 0)
	{
		data->line->floor_x_wall = data->ray->map[0] + 1.0;
		data->line->floor_y_wall = data->ray->map[1] + data->line->wall_x;
	}
	else if ((data->ray->side == NORTH || data->ray->side == SOUTH) && data->ray->ray_dir[1] > 0)
	{
		data->line->floor_x_wall = data->ray->map[0] + data->line->wall_x;
		data->line->floor_y_wall = data->ray->map[1];
	}
	else if ((data->ray->side == NORTH  || data->ray->side == SOUTH) && data->ray->ray_dir[1] < 0)
	{
		data->line->floor_x_wall = data->ray->map[0] + data->line->wall_x;
		data->line->floor_y_wall = data->ray->map[1] + 1.0;
	}
}

void	init_data_floor(t_data *data, int x)
{
	//data->line->dist_wall = data->line->perp_wall_dist;
	data->line->dist_player  = 0.0;
	// if (data->line->draw_end < 0)
	// 	data->line->draw_end = M_H;
}

void	pixel_textured_floor(t_data *data,	int x, int y, double current_floor[2])
{
	int	color[2];

	color[0] = ft_get_pixel_img(data->line->texture[4], (int)(current_floor[0] * data->line->texture[4].width) % data->line->texture[4].width,
		(int)(current_floor[1] * data->line->texture[4].height) % data->line->texture[4].height);
	//color[1] = ft_get_pixel_img(data->line->texture[5], (int)(current_floor[0] * data->line->texture[5].width) % data->line->texture[4].width, (int)(current_floor[1] * data->line->texture[5].height) % data->line->texture[5].height);
	my_mlx_pixel_put(data->img, x, y, color[0]);
	//my_mlx_pixel_put(data->img, x, M_H - y, color[1]);
}

void	pixel_textured_celling(t_data *data, int x, int y, double current_floor[2])
{
	int	color[2];

	// color[0] = ft_get_pixel_img(data->line->texture[4], (int)(current_floor[0] * data->line->texture[4].width) % data->line->texture[4].width, (int)(current_floor[1] * data->line->texture[4].height) % data->line->texture[4].height);
	color[1] = ft_get_pixel_img(data->line->texture[5], (int)(current_floor[0] * data->line->texture[5].width) % data->line->texture[5].width,
		(int)(current_floor[1] * data->line->texture[5].height) % data->line->texture[5].height);
	// my_mlx_pixel_put(data->img, x, y, color[0]);
	my_mlx_pixel_put(data->img, x, y, color[1]);
}

int	central_ray(t_data *data)
{
	return (data->ray->ray_dir[0] == data->player.v_dir[0]
			&& data->ray->ray_dir[1] == data->player.v_dir[1]);
}

void	draw_textures_floor_celling(t_data *data, int x)
{
	int	y;
	double	weight;
	double	current_floor[2];
	double	floor_tex[2];

	y = data->line->draw_end + 1;
	while (y < M_H)
	{
		data->line->current_dist = M_H / (2.0 * (y - data->player.offset_y) - M_H);
		weight = (data->line->current_dist - data->line->dist_player) / (data->zdist[x] - data->line->dist_player);
		current_floor[0] = weight * data->line->floor_x_wall + (1.0 - weight) * data->player.position[0];
		current_floor[1] = weight * data->line->floor_y_wall + (1.0 - weight) * data->player.position[1];
		pixel_textured_floor(data, x, y, current_floor);
		y++;
	}
	y = 0;
	// while (y < data->line->draw_start - 1)
	// {
	// 	data->line->current_dist = M_H / (2.0 * (y - data->player.offset_y) - M_H);
	// 	weight = (data->line->current_dist - data->line->dist_player) / (data->zdist[x] - data->line->dist_player);
	// 	current_floor[0] = weight * data->line->floor_x_wall + (1.0 - weight) *  data->player.position[0];
	// 	current_floor[1] = weight * data->line->floor_y_wall + (1.0 - weight) * data->player.position[1];
	// 	if (central_ray(data))
	// 	{
	// 		//printf("cel_x; %f  cel_y; %f\n", current_floor[0], current_floor[1]);
	// 	}
			
	// 	pixel_textured_celling(data, x, y, current_floor);
	// 	y++;
	// }
}

void	draw_floor_celling(t_data *data, int x)
{
	define_side_floor(data, x);
	init_data_floor(data, x);
	draw_textures_floor_celling(data, x);
}