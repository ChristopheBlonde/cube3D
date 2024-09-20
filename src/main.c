/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:20:03 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/19 08:53:54 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_win	*win;

	init_map(&map);
	if (argc != 2)
		return (1);
	if (!initialize_map(&map, argv[1]))
		return (1);
	win = ft_initmlx();
	mlx_loop(win->mlx);
	free_map(&map);
	return (0);
}
