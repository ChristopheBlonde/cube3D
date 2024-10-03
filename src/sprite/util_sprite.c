/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:09:37 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/03 15:20:30 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

t_sprite	*new_sprite(char *file)
{
	t_sprite	*sprite;
	int			fd;

	sprite = NULL;
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(((char **)file)[1], 2);
	ft_putstr_fd(RESET, 2);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd(ERR, 2);
		ft_putstr_fd(RESET, 2);
		return (NULL);
	}
	close(fd);
	return (sprite);
}
