/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:45:47 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/03 15:18:07 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "libft.h"
# include "error.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_img t_img;

typedef struct s_sprite
{
	t_img	*img;
	int		width;
	int		height;

}	t_sprite;

t_sprite	*new_sprite(char *file);

#endif
