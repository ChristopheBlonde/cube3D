/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:17:14 by cblonde           #+#    #+#             */
/*   Updated: 2024/01/16 17:52:50 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	if (!lst)
		return ;
	if (*lst != NULL)
	{
		last = *lst;
		while (last->next)
			last = last->next;
		new->previous = last;
		last->next = new;
	}
	else
		*lst = new;
}
