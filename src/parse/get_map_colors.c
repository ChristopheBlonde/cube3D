/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:51:50 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/16 16:20:16 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	get_floor_color(t_map *map, char **arr, char *str, int i)
{
	arr = ft_split(str, ',');
	if (!arr)
		err_alloc();
	if (!arr)
		return (false);
	if (ft_arrlen((void **)arr) != 3)
	{
		ft_free_array((void **)arr);
		return (err_color(0));
	}
	while (++i < 3)
	{
		if (ft_atoi(arr[i]) >= 0 && ft_atoi(arr[i]) <= 255)
			map->floor[i] = ft_atoi(arr[i]);
		else
		{
			ft_free_array((void **)arr);
			return (err_color(1));
		}
	}
	ft_free_array((void **)arr);
	return (1);
}

static bool	get_ceiling_color(t_map *map, char **arr, char *str, int i)
{
	arr = ft_split(str, ',');
	if (!arr)
		err_alloc();
	if (!arr)
		return (false);
	if (ft_arrlen((void **)arr) != 3)
	{
		ft_free_array((void **)arr);
		return (err_color(0));
	}
	while (++i < 3)
	{
		if (ft_atoi(arr[i]) >= 0 && ft_atoi(arr[i]) <= 255)
			map->ceiling[i] = ft_atoi(arr[i]);
		else
		{
			ft_free_array((void **)arr);
			return (err_color(1));
		}
	}
	ft_free_array((void **)arr);
	return (1);
}

bool	get_map_colors(t_map *map, char *str)
{
	char	**arr;

	arr = NULL;
	if (!ft_strncmp(str, "F", 1))
	{
		str++;
		if (*str != ' ')
			return (err_arg());
		while (ft_isspace(*str))
			str++;
		return (get_floor_color(map, arr, str, -1));
	}
	if (!ft_strncmp(str, "C", 1))
	{
		str++;
		if (*str != ' ')
			return (err_arg());
		while (ft_isspace(*str))
			str++;
		return (get_ceiling_color(map, arr, str, -1));
	}
	return (true);
}
