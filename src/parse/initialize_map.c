/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:29:41 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/03 14:23:07 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	check_file_ext(char *path)
{
	size_t	len;

	len = 0;
	if (!path)
		return (false);
	len = ft_strlen(path);
	if (len < 5 || ft_strncmp(&path[len - 4], ".cub", -1))
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd(ERR, 2);
		ft_putstr_fd(DYELLOW, 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(ERREXTENTION, 2);
		ft_putstr_fd(RESET, 2);
		return (false);
	}
	return (true);
}

static char	**get_map(char **arr, size_t start, size_t size)
{
	char	**map;
	size_t	i;
	size_t	map_len;

	i = 0;
	map = NULL;
	map_len = size - start;
	map = (char **)ft_calloc(map_len + 1, sizeof(char *));
	if (!map)
		ft_free_array((void **)arr);
	if (!map)
		return (err_alloc());
	while (i < map_len)
	{
		map[i] = ft_strdup(arr[start]);
		if (!map[i])
		{
			ft_free_array((void **)arr);
			ft_free_array((void **)map);
			return (err_alloc());
		}
		start++;
		i++;
	}
	return (map);
}

static char	**implement_t_map(t_map *map, char *file)
{
	char	**arr;
	size_t	i;
	size_t	arr_len;
	char	*tmp;

	i = 0;
	arr = ft_split(file, '\n');
	if (!arr)
		return (err_alloc());
	arr_len = ft_arrlen((void **)arr);
	while (i < arr_len)
	{
		tmp = arr[i];
		while (ft_isspace(*tmp))
			tmp++;
		if (*tmp == '1' || *tmp == '0')
			break ;
		if (!get_infos(map, arr, i))
			return (NULL);
		i++;
	}
	map->map = get_map(arr, i, arr_len);
	if (!map->map)
		return (NULL);
	return (arr);
}

bool	initialize_map(t_map *map, char *path)
{
	char	*file;
	char	**arr;

	map_validated(0);
	if (!check_file_ext(path))
		return (false);
	file = ft_readfile(path);
	if (!file)
		return (false);
	arr = implement_t_map(map, file);
	if (!arr)
	{
		free(file);
		return (false);
	}
	free(file);
	ft_free_array((void **)arr);
	if (!handle_map_err(map))
	{
		free_map(map);
		return (false);
	}
	map_validated(1);
	return (true);
}
