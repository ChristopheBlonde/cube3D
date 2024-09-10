/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:12:00 by cblonde           #+#    #+#             */
/*   Updated: 2024/01/16 12:21:26 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dlist	*ft_lstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*head;
	t_dlist	*tmp;

	if (!lst || !*f || !*del)
		return (NULL);
	head = NULL;
	while (lst != NULL)
	{
		tmp = ft_dlstnew(f(lst->content));
		if (tmp == NULL)
		{
			ft_dlstclear(&head, del);
			return (NULL);
		}
		ft_dlstadd_back(&head, tmp);
		lst = lst->next;
	}
	return (head);
}
