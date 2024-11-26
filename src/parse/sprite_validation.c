/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:45:36 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/26 12:44:28 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	is_valid_xpm(char *file)
{
	size_t	len;

	len = 0;
	if (!file)
		return (false);
	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(&file[len - 4], ".xpm", -1))
		return (err_sprite(0, file));
	return (true);
}

static bool	add_sprite(t_map *map, char *str)
{
	bool	animated;

	animated = false;
	if (str[-1] == 'A')
		animated = true;
	while (ft_isspace(*str))
		str++;
	if (animated)
	{
		str--;
		*str = 'A';
	}
	if (map->curr_sprite >= map->sprite_nb)
		return (err_sprite(4, NULL));
	map->sprites[map->curr_sprite] = ft_strdup(str);
	if (!map->sprites[map->curr_sprite])
		return (err_sprite(3, NULL));
	if (map->curr_sprite < map->sprite_nb)
		(map->curr_sprite)++;
	else
		return (err_sprite(4, NULL));
	return (true);
}

bool	get_sprite(t_map *map, char *str)
{
	if (!ft_strncmp(str, "SPN", 3))
	{
		str += 3;
		if (!valid_spn(map, str))
			return (0);
		map->sprite_nb = ft_atoi(str);
		if (map->sprite_nb != 0)
		{
			map->sprites
				= (char **)ft_calloc(map->sprite_nb + 1, sizeof(char *));
			if (!map->sprites)
				return (err_sprite(3, NULL));
		}
	}
	if (!ft_strncmp(str, "SPR", 3) || !ft_strncmp(str, "SPA", 3))
	{
		str += 3;
		if (!ft_isspace(*str))
			return (err_arg());
		if (map->sprite_nb == 0)
			return (err_sprite(2, NULL));
		if (!add_sprite(map, str))
			return (false);
	}
	return (true);
}
