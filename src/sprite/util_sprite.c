/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:09:37 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/07 09:35:07 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

#include <stdio.h> //TODO
static bool	get_xpm_info(char *str, t_sprite *sprite)
{
	char	**arr;
	bool	error;

	arr = NULL;
	error = false;
	if (!str)
		return (false);
	arr = ft_split(&str[1], ' ');
	if (!arr)
		return (false);
	if (ft_arrlen((void **)arr) < 2)
		error = true;
	sprite->width = ft_atoi(arr[0]);
	sprite->height = ft_atoi(arr[1]);
	if (sprite->width <= 0 || sprite->height <= 0)
		error = true;
	ft_free_array((void **)arr);
	if (error)
		return (false);
	return (true);
}

static bool	get_sprite_size(char *file, t_sprite *sprite)
{
	int		fd;
	char	**arr;
	char	buffer[1024];
	ssize_t	read_size;
	bool	info;

	arr = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (err_sprite(1, NULL));
	read_size = read(fd, buffer, 1022);
	if (read_size <= 0)
		return (false);
	buffer[read_size] = '\0'; 
	arr = ft_split(buffer, '\n');
	if (!arr)
		return (false);
	info = get_xpm_info(arr[2], sprite);
	ft_free_array((void **)arr);
	if (!info)
		return (false);
	close(fd);
	return (true);
}

t_sprite	*new_sprite(char *file)
{
	t_sprite	*sprite;

	sprite = NULL;
	sprite = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	if (!sprite)
		return (sprite);
	if(!get_sprite_size(file, sprite))
	{
		free(sprite);
		return (NULL);
	}
	printf("width:%d, height:%d\n", sprite->width, sprite->height);
	return (sprite);
}
