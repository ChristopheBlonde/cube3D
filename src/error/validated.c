/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validated.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:25:22 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/18 13:29:52 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	map_validated(size_t n)
{
	if (n == 0)
	{
		ft_putstr_fd(CYAN, 1);
		ft_putstr_fd(INITMAP, 1);
	}
	if (n == 1)
	{
		ft_putstr_fd(GREEN, 1);
		ft_putstr_fd(VALIDMAP, 1);
	}
	ft_putstr_fd(RESET, 1);
	return ;
}
