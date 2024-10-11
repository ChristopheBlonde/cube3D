/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:51:58 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/10 16:52:47 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget(t_list *lst, int index)
{
	t_list	*obj;
	int		i;

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
