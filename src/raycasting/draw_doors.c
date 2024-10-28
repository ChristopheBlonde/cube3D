# include "cube.h"

double	calculate_perp_door_dist(t_data *data)
{
	if (data->ray->side == EAST || data->ray->side == WEST)
	{
		return (data->ray->side_dist_x - data->ray->delta_dist_x / 2);
	}
	else
	{
		return (data->ray->side_dist_y - data->ray->delta_dist_y / 2);
	}
}

void	init_tex_line_door(t_data *data)
{
	double	wall_x;
	int		tex_width;

	data->line->tex_num = 6;
	tex_width = data->line->texture[data->line->tex_num].width;
	if (data->ray->side == EAST || data->ray->side == WEST)
		wall_x = data->player.position[1]
			+ data->line->perp_wall_dist * data->ray->ray_dir[1];
	else
		wall_x = data->player.position[0]
			+ data->line->perp_wall_dist * data->ray->ray_dir[0];
	wall_x -= floor(wall_x);
	data->line->tex_x = (int)(wall_x * (double)(tex_width));
	if ((data->ray->side == EAST || data->ray->side == WEST)
		&& data->ray->ray_dir[0] > 0)
		data->line->tex_x = tex_width - data->line->tex_x - 1;
	if ((data->ray->side == SOUTH || data->ray->side == NORTH)
		&& data->ray->ray_dir[1] < 0)
		data->line->tex_x = tex_width - data->line->tex_x - 1;
}

static void	init_door_line(t_data *data)
{
	data->line->perp_wall_dist = data->ray->door->perp_door_dist;
	data->line->line_height = (M_H / data->line->perp_wall_dist);
	data->line->draw_start = (-data->line->line_height / 2 + M_H / 2)
		+ data->player.offset_y;
	if (data->line->draw_start < 0)
		data->line->draw_start = 0;
	data->line->draw_end = (data->line->line_height / 2 + M_H / 2)
		+ data->player.offset_y;
	if (data->line->draw_end >= M_H)
		data->line->draw_end = M_H - 1;
	init_tex_line_door(data);
}

static void	 draw_texture_color(t_data *data, int x, int i)
{
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;
	t_img	texture;

	texture = data->line->texture[data->line->tex_num];
	step = 1.0 * texture.height / data->line->line_height;
	tex_pos = (data->line->draw_start - data->player.offset_y - M_H / 2
			+ data->line->line_height / 2) * step;
	while (i < data->line->draw_end)
	{
		tex_y = (int)tex_pos & (texture.height - 1);
		tex_pos += step;
		color = ft_get_pixel_img(texture, data->line->tex_x, tex_y);
		if (color != (int)0xFF000000)
			my_mlx_pixel_put(data->img, x, i, color);
		i++;
	}
}

void	draw_doors(t_data *data, int x)
{
	init_door_line(data);
	draw_texture_color(data, x, data->line->draw_start);
}