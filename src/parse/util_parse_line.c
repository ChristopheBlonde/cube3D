/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_parse_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:58:16 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/26 12:17:37 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	is_num(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '.')
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid_arg(char *str)
{
	bool	result;

	result = false;
	if (!ft_strncmp(str, "NO ", 3) || str[0] == '1' || str[0] == '0'
		|| !ft_strncmp(str, "SO ", 3) || !ft_strncmp(str, "SO\t", 3)
		|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "WE\t", 3)
		|| !ft_strncmp(str, "EA ", 3) || !ft_strncmp(str, "EA\t", 3)
		|| !ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "F\t", 2)
		|| !ft_strncmp(str, "C ", 2) || !ft_strncmp(str, "C\t", 2)
		|| !ft_strncmp(str, "SPN ", 4) || !ft_strncmp(str, "SPN\t", 4)
		|| !ft_strncmp(str, "SPR ", 4) || !ft_strncmp(str, "SPR\t", 4)
		|| !ft_strncmp(str, "SPA ", 4) || !ft_strncmp(str, "SPA\t", 4))
		result = true;
	if (!result)
		err_attribute(8);
	return (result);
}
