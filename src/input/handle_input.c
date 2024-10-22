#include "cube.h"

int	zero_input(int *keyboard, int size)
{
	int	i;

	i = 0;
	while (i < size && !keyboard[i])
		i++;
	if (keyboard[i])
		return (0);
	return (1);
}

void	handle_movement_and_rotation(t_data *data)
{
	int	*keyboard;

	keyboard = data->player.keyboard;
	if (keyboard[KEY_W])
		move_player(&data->player, &data->map, KEY_W, 0.12);
	if (keyboard[KEY_A])
		move_player(&data->player, &data->map, KEY_A, 0.08);
	if (keyboard[KEY_S])
		move_player(&data->player, &data->map, KEY_S, 0.12);
	if (keyboard[KEY_D])
		move_player(&data->player, &data->map, KEY_D, 0.08);
	if (keyboard[KEY_RIGHT])
		rotate_player(&data->player, MOUSE_SPEED);
	if (keyboard[KEY_LEFT])
		rotate_player(&data->player, -MOUSE_SPEED);
}

void	check_x_axis(t_data *data, int x)
{
	// if (x > M_W * 0.5)
		rotate_player(&data->player, MOUSE_SPEED * (x - M_W / 2) / 100);
	// else if (x < M_W * 0.5)
	// 	rotate_player(&data->player, -MOUSE_SPEED * PI);

}

void	check_y_axis(t_data *data, int y)
{
	static double	offset_y = 0;

	offset_y -= (y - M_H / 2);
	if (offset_y > 450)
		offset_y = 450;
	if (offset_y < -450)
		offset_y = -450;
	data->player.offset_y = offset_y;
	// printf("off_y; %f\n", data->player.offset_y);
	// if (y < M_H * 0.5)
	// 	data->player.offset_y = -10;
	// if (y > M_H * 0.5)
	// 	data->player.offset_y = 10;
}

int	out_of_screen(int x, int y)
{
	if (x < 0 || x > M_W ||
		y < 0 || y > M_H)
		return (1);
	return (0);
}

void	handle_mouse(t_data *data)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(data->win->mlx_ptr, data->win->win_ptr, &x, &y);
	if (!out_of_screen(x, y))
	{
		check_x_axis(data, x);
		check_y_axis(data, y);
	}
	mlx_mouse_move(data->win->mlx_ptr, data->win->win_ptr, M_W * 0.5, M_H * 0.5);
}

int	handle_input(t_data *data)
{
	int	*keyboard;

	keyboard = data->player.keyboard;
	// if (zero_input(keyboard, KEY_NB))
	// 	return (1);
	handle_mouse(data);
	handle_movement_and_rotation(data);
	return (0);
}