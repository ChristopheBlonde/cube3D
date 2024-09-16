/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:28:53 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/16 15:42:17 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

size_t	err_arg(void)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(ERR, 2);
	ft_putstr_fd(DYELLOW, 2);
	ft_putstr_fd(ERRARG, 2);
	ft_putstr_fd(RESET, 2);
	return (0);
}

size_t	err_open(char *s)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(ERR, 2);
	ft_putstr_fd(DYELLOW, 2);
	perror(s);
	ft_putstr_fd(RESET, 2);
	return (0);
}

size_t	err_duplicate(size_t n)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(ERR, 2);
	ft_putstr_fd(DYELLOW, 2);
	if (n == 0)
		ft_putstr_fd(ERRDNO, 2);
	if (n == 1)
		ft_putstr_fd(ERRDSO, 2);
	if (n == 2)
		ft_putstr_fd(ERRDWE, 2);
	if (n == 3)
		ft_putstr_fd(ERRDEA, 2);
	ft_putstr_fd(RESET, 2);
	return (0);
}

size_t	err_color(size_t n)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(ERR, 2);
	ft_putstr_fd(DYELLOW, 2);
	if (n == 0)
		ft_putstr_fd(ERRNCOLOR, 2);
	if (n == 1)
		ft_putstr_fd(ERRRACOLOR, 2);
	ft_putstr_fd(RESET, 2);
	return (0);
}
