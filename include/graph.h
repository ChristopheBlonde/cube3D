/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:32:41 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/24 09:33:00 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include "mlx.h"
# include "libft.h"
# include "math.h"
# include "point.h"

# define M_W 1800
# define M_H 1000
# define M_NAME "cub3D"
# define M_RED 84
# define M_GREEN 122
# define M_BLUE 165

typedef struct s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
}	t_win;

typedef struct	s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
	size_t	width;
	size_t	height;
}	t_img;

t_win	ft_initmlx(void);
void	free_win(t_win *win);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		get_color(double dist, int r, int g, int b);
t_img	new_img(t_win win, int w, int h);
void	free_img(t_img *img);
void	draw_circle(t_img *img, t_point center, int r, int color);
void	draw_square(t_img *img, int color, size_t size, t_point curr);

#endif
