/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:16:00 by cblonde           #+#    #+#             */
/*   Updated: 2024/01/15 12:57:17 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dlist	*ft_dlstget(t_dlist *lst, int index)
{
	int		i;
	t_dlist	*obj;

	i = 0;
	obj = lst;
	if (obj == NULL)
		return (NULL);
	if (obj->next == NULL)
		return (obj);
	while (obj != NULL)
	{
		if (i >= index)
			return (obj);
		obj = obj->next;
		i++;
	}
	return (NULL);
}
