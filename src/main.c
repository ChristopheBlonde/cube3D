/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:20:03 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/07 15:46:46 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	functionTest(t_data *data) //TODO
{
	if (handle_input(data) && !update(data))
		return (0);
	ft_foreach((void **)data->arr_s, update_animation);
	raycasting(data);
	update_doors_anim(data);
	if (data->map.sprite_nb != 0)
		render_arr_sprites(data);
	render_doors(data);
	if (data->map.sprite_nb != 0)
		render_arr_sprites(data);
	if (data->mnmap->minimap)
		draw_mnmap(data);
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
	if (!init_player_sprite(&data))
		return(printf("error sprite player\n"));
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
