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
		rotate_player(&data->player, 0.01 * PI);
	if (keyboard[KEY_LEFT])
		rotate_player(&data->player, - 0.01 * PI);
}

int	handle_input(t_data *data)
{
	int	*keyboard;

	keyboard = data->player.keyboard;
	if (zero_input(keyboard, KEY_NB))
		return (1);
	handle_movement_and_rotation(data);
	return (0);
}