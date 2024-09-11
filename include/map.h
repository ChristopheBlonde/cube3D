/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:40:37 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/11 12:02:46 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct	s_map
{
	int	height;
	int	width;
	int	floor[3];
	int	ceiling[3];
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
} t_map;

#endif
