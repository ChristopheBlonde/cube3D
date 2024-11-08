/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:45:47 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/08 14:46:55 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "libft.h"
# include "error.h"
# include "mlx.h"
# include "data.h"
# include "graph.h"
# include "parse.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_img			t_img;
typedef struct s_data			t_data;
typedef struct s_init_sprite	t_s_init;

typedef enum e_sprite_type
{
	PLAYER,
	SPRITE,
	ANIMSPRITE,
}	t_stype;

typedef struct s_render
{
	double	cam_x;
	double	cam_y;
	double	inv_det;
	double	trf_x;
	double	trf_y;
	int		s_sc_x;
	int		s_h;
	int		s_w;
	int		start_y;
	int		end_y;
	int		start_x;
	int		end_x;
	int		tex_x;
	int		tex_y;
	int		v_m_sc;
	int		u_div;
	int		v_div;
	double	v_move;
	double	dalpha;
}	t_rend;

typedef struct s_sprite_slice
{
	int	x;
	int	y;
	int	width;
	int	height;
}	t_sprite_slice;

typedef struct s_animation
{
	t_list		*frames;
	int			width;
	int			height;
	int			delay;
	int			_tmp_delay;
	int			current_frame_num;
	long int	last_updated;
	long int	frame_count;
}	t_anim;

typedef struct s_sprite
{
	t_list	*anim;
	t_img	*img;
	int		width;
	int		height;
	double	pos_x;
	double	pos_y;
	t_rend	render;
	bool	animated;
	t_stype	type;
	int		lst_nb;
}	t_sprite;

t_sprite	*new_sprite(t_data *data, char *file);
void		free_sprite(t_sprite *sprite);
void		free_arr_sprites(t_sprite **arr);
void		render_arr_sprites(t_data *data);
void		render_sprite(t_data *data, t_sprite *sprite);
size_t		**sort_sprites(t_data *data);
void		add_frame(t_anim *animation,
				t_sprite *sprite, t_sprite_slice slice);
t_anim		*ft_slice_sprite(t_sprite *sprite, t_sprite_slice slice,
				int frames, int delay);
void		init_sprite(t_sprite *sprite, t_s_init *info);
void		update_animation(void *ptr);
bool		init_door_sprite(t_data *data);
t_img		*get_current_img(t_sprite *sprite);
void		update_doors_anim(t_data *data);
void		update_player_pos(t_data *data);
void		sort_door(t_data *data);

#endif
