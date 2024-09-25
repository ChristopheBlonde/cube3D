/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:32:41 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/24 15:36:27 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include "mlx.h"
# include "libft.h"
# include "math.h"
# include "point.h"
# include <X11/keysym.h>
# include "data.h"

# define M_W 1800
# define M_H 1000
# define M_NAME "cub3D"
# define M_RED 84
# define M_GREEN 122
# define M_BLUE 165
# define PI 3.1415926535

typedef struct s_data t_data;

typedef struct s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
}	t_win;

typedef struct	s_img
{
	t_win	*win;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
	size_t	width;
	size_t	height;
}	t_img;

t_win	*ft_initmlx(void);
void	free_win(t_win *win);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		get_color(double dist, int r, int g, int b);
t_img	*new_img(t_win *win, int w, int h);
void	free_img(t_img *img);
void	draw_circle(t_img *img, t_point center, int r, int color);
int		handle_keypress(int keysym, t_data *data);

#endif
