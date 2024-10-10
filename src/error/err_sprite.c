/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 08:27:32 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/09 16:23:38 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

static void	puterror(void)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(ERR, 2);
	ft_putstr_fd(DYELLOW, 2);
}

bool	err_sprite(size_t n, char *file)
{
	puterror();
	if (n == 0)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(ERREXXPM, 2);
	}
	if (n == 1)
		ft_putstr_fd(FAILOPEN, 2);
	if (n == 2)
		ft_putstr_fd(NOSPRITENB, 2);
	if (n == 3)
		ft_putstr_fd(FAILALLOC, 2);
	if (n == 4)
		ft_putstr_fd(ERRNSPRITE, 2);
	if (n == 5)
		ft_putstr_fd(ERRSPRITEARG, 2);
	if (n == 6)
		ft_putstr_fd(ERRSPRITEPOS, 2);
	if (n == 7)
		ft_putstr_fd(ERRSPOS, 2);
	if (n == 8)
		ft_putstr_fd(ERRNSPOS, 2);
	ft_putstr_fd(RESET, 2);
	return (false);
}
