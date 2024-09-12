/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:29:41 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/12 16:47:23 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	check_file_ext(char *path)
{
	char *tmp;

	if (!path)
		return (false);
	tmp = path;
	tmp += ft_strlen(path) - 4;
	if (ft_strncmp(tmp, ".cub", -1))
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
	{
		ft_free_array((void **)arr);
		return (NULL);
	}
	while (i < map_len)
	{
		map[i] = ft_strdup(arr[start]);
		start++;
		i++;
	}
	return (map);
}

static char **get_array(char *file)
{
	char	**arr;
	size_t	i;
	size_t	arr_len;
	char	*tmp;
	char	**map;

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
		i++;
	}
	map = get_map(arr, i, arr_len);
	ft_putstr_fd(CYAN, 1);
	for (size_t j = 0; map[j]; j++)
		ft_putendl_fd(map[j], 1);
	ft_putstr_fd(RESET, 1);
	return (arr);
}

bool	initialize_map(t_map *map, char *path)
{
	char	*file;
	char	**arr;

	(void)map;
	if (!check_file_ext(path))
		return (false);
	file = ft_readfile(path);
	if (!file)
		return (false);
	arr = get_array(file);
	free(file);
	free(arr);
	return (true);
}
