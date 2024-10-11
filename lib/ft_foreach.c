/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:14:01 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/11 13:44:01 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_foreach(void **arr, void (*f)(void *ptr))
{
	size_t	i;

	i = 0;
	if (!arr || !f)
		return ;
	while (arr[i])
	{
		f(arr[i]);
		i++;
	}
	return ;
}
