/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:45:47 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/08 14:02:43 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "libft.h"
# include "error.h"
# include "mlx.h"
# include "data.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_img	t_img;
typedef struct s_data	t_data;

typedef struct s_sprite
{
	t_img	*img;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
	double	cam_x;
	double	cam_y;
}	t_sprite;

t_sprite	*new_sprite(t_data *data, char *file);
void		free_sprite(t_sprite *sprite);
bool		init_arr_sprites(t_data *data);
void		free_arr_sprites(t_sprite **arr);
void		render_sprite(t_data *data);

#endif
