/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:01:43 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/04 15:22:27 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int	alpha(double opacity, int cback, int cfront)
{
	int	r;
	int	g;
	int	b;

	r = (cback >> 16 & 0xFF) * (1 - opacity) + (cfront >> 16 & 0xFF) * opacity;
	g = (cback >> 8 & 0xFF) * (1 - opacity) + (cfront >> 8 & 0xFF) * opacity;
	b = (cback & 0xFF) * (1 - opacity) + (cfront & 0xFF) * opacity;
	return ((int)(255 << 24 | r << 16 | g << 8 | b));
}

int	get_color(double dist, int r, int g, int b)
{
	int	color;

	color = ((int)(dist * 255) << 24) | (r << 16) | (g << 8) | b;
	return (color);
}
