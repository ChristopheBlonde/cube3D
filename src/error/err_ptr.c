/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:42:29 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/12 15:56:33 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	*err_alloc(void)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(ERR, 2);
	ft_putstr_fd(DRED, 2);
	ft_putstr_fd(FAILALLOC, 2);	
	ft_putstr_fd(RESET, 2);
	return (NULL);
}
