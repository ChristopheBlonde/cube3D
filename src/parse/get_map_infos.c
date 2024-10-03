/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:46:22 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/03 13:56:11 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static	size_t	get_no(t_map *map, char *str)
{
	int	fd;

	if (!ft_strncmp(str, "NO", 2))
	{
		str += 2;
		if (*str != ' ')
			return (err_arg());
		if (!is_valid_xpm(str))
			return (0);
		while (ft_isspace(*str))
			str++;
		fd = open(str, O_RDONLY);
		if (fd < 0)
			return (err_open(str));
		close(fd);
		if (map->no)
			return (err_duplicate(0));
		map->no = ft_strdup(str);
		if (!map->no)
		{
			err_alloc();
			return (0);
		}
	}
	return (1);
}

static	size_t	get_so(t_map *map, char *str)
{
	int	fd;

	if (!ft_strncmp(str, "SO", 2))
	{
		str += 2;
		if (*str != ' ')
			return (err_arg());
		if (!is_valid_xpm(str))
			return (0);
		while (ft_isspace(*str))
			str++;
		fd = open(str, O_RDONLY);
		if (fd < 0)
			return (err_open(str));
		close(fd);
		if (map->so)
			return (err_duplicate(1));
		map->so = ft_strdup(str);
		if (!map->so)
		{
			err_alloc();
			return (0);
		}
	}
	return (1);
}

static	size_t	get_we(t_map *map, char *str)
{
	int	fd;

	if (!ft_strncmp(str, "WE", 2))
	{
		str += 2;
		if (*str != ' ')
			return (err_arg());
		if (!is_valid_xpm(str))
			return (0);
		while (ft_isspace(*str))
			str++;
		fd = open(str, O_RDONLY);
		if (fd < 0)
			return (err_open(str));
		close(fd);
		if (map->we)
			return (err_duplicate(2));
		map->we = ft_strdup(str);
		if (!map->we)
		{
			err_alloc();
			return (0);
		}
	}
	return (1);
}

static	size_t	get_ea(t_map *map, char *str)
{
	int	fd;

	if (!ft_strncmp(str, "EA", 2))
	{
		str += 2;
		if (*str != ' ')
			return (err_arg());
		if (!is_valid_xpm(str))
			return (0);
		while (ft_isspace(*str))
			str++;
		fd = open(str, O_RDONLY);
		if (fd < 0)
			return (err_open(str));
		close(fd);
		if (map->ea)
			return (err_duplicate(3));
		map->ea = ft_strdup(str);
		if (!map->ea)
		{
			err_alloc();
			return (0);
		}
	}
	return (1);
}

bool	get_infos(t_map *map, char **arr, size_t i)
{
	size_t	error;

	error = 0;
	ft_strstrim(arr[i]);
	if (!error && !get_no(map, arr[i]))
		error = 1;
	if (!error && !get_so(map, arr[i]))
		error = 1;
	if (!error && !get_we(map, arr[i]))
		error = 1;
	if (!error && !get_ea(map, arr[i]))
		error = 1;
	if (!error && !get_map_colors(map, arr[i]))
		error = 1;
	if (error)
	{
		ft_free_array((void **)arr);
		free_map(map);
		return (false);
	}
	return (true);
}
