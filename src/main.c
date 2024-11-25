/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:20:03 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/25 11:34:39 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	err_init_exit(t_data *data, size_t n)
{
	if (n == 0)
	{
		err_global();
		ft_putstr_fd(USAGE, 2);
	}
	if (n == 1)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd(ERRINIT, 2);
	}
	ft_putstr_fd(RESET, 2);
	if (n)
		free_data(data);
	return (1);
}

static int	render_game(t_data *data)
{
	if (handle_input(data) && !update(data))
		return (0);
	ft_foreach((void **)data->arr_s, update_animation);
	raycasting(data);
	update_doors_anim(data);
	if (data->map.sprite_nb != 0)
		render_arr_sprites(data);
	if (data->visible_door)
		render_doors(data);
	if (data->map.sprite_nb != 0)
		render_arr_sprites(data);
	if (data->mnmap->minimap)
		draw_mnmap(data);
	mlx_put_image_to_window(data->win->mlx_ptr,
		data->win->win_ptr, data->img->img_ptr, 0, 0);
	return (1);
}

static void	mlx_run_loop(t_data *data)
{
	mlx_loop_hook(data->win->mlx_ptr, &render_game, data);
	mlx_hook(data->win->win_ptr, 17, 1L << 0, exit_game, data);
	mlx_hook(data->win->win_ptr,
		KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win->win_ptr,
		KeyRelease, KeyReleaseMask, &handle_keyrelease, data);
	mlx_loop(data->win->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
		return (err_init_exit(&data, 0));
	if (!init_data(&data, argv))
		return (err_init_exit(&data, 1));
	if (!init_player_sprite(&data))
		return (err_init_exit(&data, 1));
	mlx_run_loop(&data);
	free_data(&data);
	return (0);
}
