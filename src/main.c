/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:20:03 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/28 17:27:18 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


static int	functionTest(t_data *data) //TODO
{
	if (handle_input(data) && !update(data))
		return (0);
	ft_foreach((void **)data->arr_s, update_animation);
	raycasting(data);
	update_animation(data->door_s);
	if (data->mnmap->minimap)
		draw_mnmap(data);
	if (data->map.sprite_nb != 0)
		render_sprite(data);
	mlx_put_image_to_window(data->win->mlx_ptr,
		data->win->win_ptr, data->img->img_ptr, 0, 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
		return (1);
	if (!init_data(&data, argv))
	{
		free_data(&data);
		return (1);
	}
	mlx_mouse_hide(data.win->mlx_ptr, data.win->win_ptr);
	mlx_loop_hook(data.win->mlx_ptr, &functionTest, &data);
	mlx_hook(data.win->win_ptr,
		KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win->win_ptr,
		KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_loop(data.win->mlx_ptr);
	free_data(&data);
	return (0);
}
