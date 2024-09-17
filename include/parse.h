/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:34:19 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/17 13:14:04 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include "error.h"
# include "def_color.h"
# include "libft.h"
# include "map.h"

char	*ft_readfile(char *file);
bool	initialize_map(t_map *map, char *path);
bool	get_infos(t_map *map, char **arr, size_t i);
bool	get_map_colors(t_map *map, char *str);
bool	handle_map_err(t_map *map);

#endif
