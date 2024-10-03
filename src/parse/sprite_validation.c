/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:45:36 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/03 14:45:15 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	is_valid_xpm(char *file)
{
	size_t	len;

	len = 0;
	if (!file)
		return (false);
	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(&file[len - 4], ".xpm", -1))
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd(ERR, 2);
		ft_putstr_fd(DYELLOW, 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(ERREXXPM, 2);
		ft_putstr_fd(RESET, 2);
		return (false);
	}
	return (true);
}
