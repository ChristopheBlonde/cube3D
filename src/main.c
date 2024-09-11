/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:20:03 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/11 17:02:05 by cblonde          ###   ########.fr       */
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
	char *file;

	if (argc != 2)
		return (1);
	file = ft_readfile(argv[1]);
	if (!file)
		return (ft_putstr_fd(ERR, 2), 1);
	ft_putendl_fd(file , 1);
	free(file);
	return (0);
}
