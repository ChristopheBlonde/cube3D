/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:58:35 by cblonde           #+#    #+#             */
/*   Updated: 2024/01/12 19:22:26 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstiter(t_dlist *lst, void (*f)(void *))
{
	if (!lst || !*f)
		return ;
	while (lst->next)
	{
		f(lst->content);
		lst = lst->next;
	}
}
