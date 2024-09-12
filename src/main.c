/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:20:03 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/12 11:42:12 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*ft_readfile(char *file);

void	open_window_mlx(void)
{
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 800, 600, "Test MLX");
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (1);
	if (!initialize_map(&map, argv[1]))
		return (1);
	return (0);
}
