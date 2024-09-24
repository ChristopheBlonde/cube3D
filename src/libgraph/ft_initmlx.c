/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:31:45 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/24 10:11:07 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_win	ft_initmlx(void)
{
	t_win win;

	win.mlx_ptr = NULL;
	win.win_ptr = NULL;
	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, M_W, M_H, M_NAME);
	return (win);
}

void	free_win(t_win *win)
{
	if (win->mlx_ptr && win->win_ptr)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	if (win->mlx_ptr)
		free(win->mlx_ptr);
}
