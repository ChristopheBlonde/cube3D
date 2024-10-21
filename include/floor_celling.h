#ifndef FLOOR_CELLING_H
# define FLOOR_CELLING_H

typedef struct s_floor_celling
{
	double	ray_dir_x0;
	double	ray_dir_y0;
	double	ray_dir_x1;
	double	ray_dir_y1;
	double	pos_z;
	double	row_dist_floor;
	double	row_dist_celling;
	double	floor_step_x;
	double	floor_step_y;
	double	floor_x;
	double	floor_y;
	double	celling_step_x;
	double	celling_step_y;
	double	celling_x;
	double	celling_y;
}	t_floor_celling;

#endif