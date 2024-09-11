/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:08:50 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/11 14:26:18 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strstrim(char *s)
{
	char	*read;
	char	*end;
	int		start;

	if (!s)
		return ;
	read = s;
	end = s;
	start = 1;
	end += ft_strlen(s) - 1;
	while (end != s && ft_isspace(*end))
		end--;
	end++;
	while (*read && read != end)
	{
		if (!ft_isspace(*read) || !start)
		{
			start = 0;
			*s = *read;
			s++;
		}
		read++;
	}
	*s = '\0';
}
