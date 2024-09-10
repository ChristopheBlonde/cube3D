/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:18:13 by cblonde           #+#    #+#             */
/*   Updated: 2024/01/15 12:43:05 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"
#include "libft.h"

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*new;

	new = ft_calloc(1, sizeof(t_dlist));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}
