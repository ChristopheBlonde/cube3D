/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:31:45 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/19 08:56:18 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_win	*ft_initmlx(void)
{
	t_win *win;

	win = (t_win *)ft_calloc(1, sizeof(t_win));
	if (!win)
		return (NULL);
	win->mlx = mlx_init();
	if (!win->mlx)
		return (NULL);
	win->win = mlx_new_window(win->mlx, M_W, M_H, M_NAME);
	if (!win->win)
		return (NULL);
	return (win);
}
