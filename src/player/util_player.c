/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:45:04 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/17 12:47:09 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_dir	get_direction(char c)
{
	if (c == 'N')
		return (NORTH);
	if (c == 'S')
		return (SOUTH);
	if (c == 'W')
		return (WEST);
	if (c == 'E')
		return (EAST);
	return (NONE);
}
