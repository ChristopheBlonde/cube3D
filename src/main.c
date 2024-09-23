/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:20:03 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/23 17:15:12 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_map		map;
	t_win		win;
	t_minimap	mnmap;
	t_img		bkg;

	init_map(&map);
	if (argc != 2)
		return (1);
	if (!initialize_map(&map, argv[1]))
		return (1);
	win = ft_initmlx();
	mnmap = init_mmap(win);
	bkg = new_img(win, M_W, M_H);
	for (int i = 0; i < M_H; i++)
		for (int j = 0; j < M_W; j++)
			my_mlx_pixel_put(&bkg, j, i, get_color(1, 84, 122, 85));
	draw_circle(&bkg, mnmap.mid, mnmap.radius,
		get_color(1, M_RED, M_GREEN, M_BLUE));
	draw_mnmap(mnmap, map, bkg);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, bkg.img_ptr, 0, 0);
	mlx_loop(win.mlx_ptr);
	free_map(&map);
	return (0);
}
