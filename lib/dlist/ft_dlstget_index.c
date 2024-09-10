/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstget_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:58:19 by cblonde           #+#    #+#             */
/*   Updated: 2024/01/22 15:58:59 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

int	ft_dlstget_index(t_dlist *lst, int *elem)
{
	t_dlist	*current;
	int		i;

	i = 0;
	if (!lst || !elem)
		return (-1);
	current = lst;
	while (*(int *)current->content != *elem && current)
	{
		current = current->next;
		i++;
	}
	return (i);
}
