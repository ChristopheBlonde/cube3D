/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:58:34 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/25 09:01:09 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		free_data(data);
		exit(0);
	}
	if (keysym == XK_w)
		move_player(&data->player, keysym, 0.083);
	if (keysym == XK_s)
		move_player(&data->player, keysym, 0.083);
	if (keysym == XK_a)
		move_player(&data->player, keysym, 0.083);
	if (keysym == XK_d)
		move_player(&data->player, keysym, 0.083);
	if (keysym == XK_Right)
		rotate_player(&data->player, 0.025 * PI);
	if (keysym == XK_Left)
		rotate_player(&data->player, -0.025 * PI);
	return (0);
}
