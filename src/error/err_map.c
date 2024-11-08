/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:19:47 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/08 12:37:40 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	err_global(void)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(ERR, 2);
	ft_putstr_fd(DYELLOW, 2);
	return ;
}

bool	err_attribute(size_t n)
{
	err_global();
	if (n == 0)
		ft_putstr_fd(ERRHEIGHT, 2);
	if (n == 1)
		ft_putstr_fd(ERRWIDTH, 2);
	if (n == 2)
		ft_putstr_fd(ERRTEXTURE, 2);
	if (n == 3)
		ft_putstr_fd(ERRMAPSIZE, 2);
	if (n == 4)
		ft_putstr_fd(ERRFCOLOR, 2);
	if (n == 5)
		ft_putstr_fd(ERRCCOLOR, 2);
	if (n == 6)
		ft_putstr_fd(ERRMPLAYER, 2);
	ft_putstr_fd(RESET, 2);
	return (false);
}
