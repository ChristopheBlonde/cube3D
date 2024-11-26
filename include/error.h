/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:20:59 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/26 12:41:51 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"
# include "def_color.h"
# include <errno.h>
# include <stdio.h>

# define ERR "Error\n"
# define FAILALLOC "Allocation fail\n"
# define FAILOPEN "Cannot open file\n"
# define FAILCLOSE "Fail close file\n"
# define ERREXTENTION ": Bad exention file\n"
# define ERREXXPM ": Exention file must be xmp\n"
# define ERRARG "Unknow argument in file\n"
# define ERRDNO "Duplicate file for north texture\n"
# define ERRDSO "Duplicate file for south texture\n"
# define ERRDWE "Duplicate file for west texture\n"
# define ERRDEA "Duplicate file for east texture\n"
# define ERRNCOLOR "Bad number arguments for rgb color\n"
# define ERRRACOLOR "rgb color must range [0-255]\n"
# define ERRFDCOLOR "Duplicated floor color\n"
# define ERRCDCOLOR "Duplicated ceiling color\n"
# define ERRDPLAYER "Find more than one player\n"
# define ERRMCLOSED "Player can escape game !\n"
# define ERRHEIGHT "Map height can't be null\n"
# define ERRWIDTH "Map width can't be null\n"
# define ERRTEXTURE "Texture map is missing\n"
# define ERRMAPSIZE "Map is too big map dimention must be under 150 000 cubes\n"
# define ERRFCOLOR "Floor color is missing\n"
# define ERRCCOLOR "Ceiling color is missing\n"
# define ERRMPLAYER "Player is missing\n"
# define ERRUNKNOW "Unknow character in map\n"
# define INITMAP "Start initialization map\n"
# define VALIDMAP "Initialization map completed\n"
# define NOSPRITENB "Sprite number must initialized\n"
# define ERRNSPRITE "Number sprite declare does not match with path given\n"
# define ERRSPRITEARG "Sprite arg must contain path and at least 1 position\n"
# define ERRSPRITEPOS "Sprite info must contain 7 arguments or 9 for animated\n"
# define ERRNSPOS "Number sprite declare does not match number position given\n"
# define ERRSPOS "sprite position impossible\n"
# define ERRINIT "Fail initialization\n"
# define USAGE "Usage: ./cub3d [map file]\n"
# define ERRARGSPRITE "Bad sprite argument\n"
# define ERRDARGS "Duplicated argument SPN\n"

void	*err_alloc(void);
size_t	err_arg(void);
size_t	err_open(char *s);
size_t	err_duplicate(size_t n);
size_t	err_color(size_t n);
size_t	err_map_invalid(size_t n);
bool	err_attribute(size_t n);
void	map_validated(size_t n);
bool	err_sprite(size_t n, char *file);
void	err_global(void);

#endif
