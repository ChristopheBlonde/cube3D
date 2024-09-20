/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:32:41 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/19 08:53:01 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include "mlx.h"
# include "libft.h"

# define M_W 1900
# define M_H 1090
# define M_NAME "cub3D"

typedef struct s_win
{
	void	*mlx;
	void	*win;
}	t_win;

t_win	*ft_initmlx(void);

#endif
