/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:51:50 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/16 13:00:00 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	get_map_colors(t_map *map, char *str)
{
	(void)map;
	ft_putstr_fd(CYAN, 1);
	ft_putendl_fd(str, 1);
	ft_putstr_fd(RESET, 1);
	return (true);
}

