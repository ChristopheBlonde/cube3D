/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:51:50 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/26 13:50:27 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	get_floor_color(t_map *map, char *str, int i)
{
	char	**arr;

	arr = NULL;
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
		if (is_num(arr[i]) && ft_atoi(arr[i]) >= 0 && ft_atoi(arr[i]) <= 255)
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

static bool	get_ceiling_color(t_map *map, char *str, int i)
{
	char	**arr;

	arr = NULL;
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
		if (is_num(arr[i]) && ft_atoi(arr[i]) >= 0 && ft_atoi(arr[i]) <= 255)
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

static bool	duplicated_color(t_map *map, size_t n)
{
	if (n == 0)
	{
		if (map->floor[0] == -1
			&& map->floor[1] == -1
			&& map->floor[2] == -1)
			return (true);
	}
	if (n == 1)
	{
		if (map->ceiling[0] == -1
			&& map->ceiling[1] == -1
			&& map->ceiling[2] == -1)
			return (true);
	}
	return (false);
}

bool	get_map_colors(t_map *map, char *str)
{
	if (!ft_strncmp(str, "F", 1))
	{
		if (!duplicated_color(map, 0))
			return (err_color(2));
		str++;
		if (!ft_isspace(*str))
			return (err_arg());
		while (ft_isspace(*str))
			str++;
		return (get_floor_color(map, str, -1));
	}
	if (!ft_strncmp(str, "C", 1))
	{
		if (!duplicated_color(map, 1))
			return (err_color(3));
		str++;
		if (!ft_isspace(*str))
			return (err_arg());
		while (ft_isspace(*str))
			str++;
		return (get_ceiling_color(map, str, -1));
	}
	return (true);
}
