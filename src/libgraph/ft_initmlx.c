/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:31:45 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/25 11:22:20 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_win	*ft_initmlx(void)
{
	t_win	*win;

	win = (t_win *)ft_calloc(1, sizeof(t_win));
	if (!win)
		return (NULL);
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
	{
		free(win);
		return (NULL);
	}
	win->win_ptr = mlx_new_window(win->mlx_ptr, M_W, M_H, M_NAME);
	if (!win->win_ptr)
	{
		free(win->mlx_ptr);
		free(win);
		return (NULL);
	}
	return (win);
}

void	free_win(t_win *win)
{
	if (win->mlx_ptr && win->win_ptr)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		mlx_destroy_display(win->mlx_ptr);
	}
	if (win->mlx_ptr)
		free(win->mlx_ptr);
}
