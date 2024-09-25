/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:05:47 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/24 17:50:33 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h> //TODO

static void	get_map_attribute(t_map *map, size_t *player, size_t *unknow)
{
	int		i;
	int		j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] != ' ' && map->map[i][j] != '1'
				&& map->map[i][j] != 'S' && map->map[i][j] != 'N'
				&& map->map[i][j] != 'W' && map->map[i][j] != 'E'
				&& map->map[i][j] != '0')
				(*unknow)++;
			if (get_direction(map->map[i][j]) != NONE && ++(*player))
			{
				map->player.dir = get_direction(map->map[i][j]);
				map->player.position[0] = (double)j;
				map->player.position[1] = (double)i;
			}
		}
		if ((size_t)j > map->width)
			map->width = (size_t)j;
	}
	map->height = (size_t)i;
}

static char	**duplicate_array(t_map *map)
{
	char	**tmp;
	size_t	i;

	i = 0;
	tmp = (char **)ft_calloc(map->height + 1, sizeof(char *));
	if (!tmp)
		return (NULL);
	while (map->map[i])
	{
		tmp[i] = (char *)ft_calloc(map->width + 1, sizeof(char));
		if (!tmp[i])
		{
			ft_free_array((void **)tmp);
			return (NULL);
		}
		ft_strlcpy(tmp[i], map->map[i], map->width + 1);
		i++;
	}
	return (tmp);
}

static void	implement_arr_test(t_map *map, char **arr, size_t x, size_t y)
{
	int	i;
	int	j;

	i = y;
	j = x;
	arr[i][j] = '2';
	if (i > 0 && arr[i - 1][j] != '1' && arr[i - 1][j] != '2')
		implement_arr_test(map, arr, x, y - 1);
	if (i < (int)map->height - 1
		&& arr[i + 1][j] != '1' && arr[i + 1][j] != '2')
		implement_arr_test(map, arr, x, y + 1);
	if (j > 0 && arr[i][j - 1] != '1' && arr[i][j - 1] != '2')
		implement_arr_test(map, arr, x - 1, y);
	if (j < (int)map->width - 1 && arr[i][j + 1] != '1' && arr[i][j + 1] != '2')
		implement_arr_test(map, arr, x + 1, y);
	return ;
}

static bool	is_closed(t_map *map)
{
	char	**w_arr;
	bool	res;	
	int		i;
	int		j;

	i = -1;
	res = true;
	w_arr = duplicate_array(map);
	if (!w_arr)
		return (false);
	implement_arr_test(map, w_arr,
		(int)map->player.position[0], (int)map->player.position[1]);
	while (++i < (int)map->height)
	{
		j = -1;
		while (++j < (int)map->width)
		{
			if ((i == 0 || i == (int)map->height) && w_arr[i][j] == '2')
				res = false;
			if ((j == 0 || j == (int)map->width) && w_arr[i][j] == '2')
				res = false;
		}
	}
	ft_free_array((void **)w_arr);
	return (res);
}

bool	handle_map_err(t_map *map)
{
	size_t	player;
	size_t	unknow;

	player = 0;
	unknow = 0;
	get_map_attribute(map, &player, &unknow);
	if (player > 1)
		return (err_attribute(6));
	if (unknow != 0)
		return (err_map_invalid(2));
	if (!missing_att(map))
		return (false);
	if (!is_closed(map))
		return (err_map_invalid(1));
	map->map[(int)map->player.position[1]][(int)map->player.position[0]] = '0';
	return (true);
}
