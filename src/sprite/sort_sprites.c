/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:38:55 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/10 10:57:29 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

static void	swap_sprite(void **arr, size_t a, size_t b)
{
	void	*tmp;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

static void	order_sprite(t_sprite **sprites, size_t **index, double **dist)
{
	size_t	i;
	size_t	j;

	i = 0;
	for (int k = 0; index[k]; k++)
		printf("index befor:%zu\n", *(index[k]));
	for (int k = 0; dist[k]; k++)
		printf("dist befor:%f\n", *(dist[k]));
	while (index[i])
	{
		j = i;
		while (dist[j])
		{
			if (dist[j] > dist[i])
			{
				swap_sprite((void **)dist, i, j);
				swap_sprite((void **)index, i, j);
				swap_sprite((void **)sprites, i, j);
			}
			j++;
		}
		i++;
	}
	for (int k = 0; index[k]; k++)
		printf("\tindex after:%zu\n", *(index[k]));
	for (int k = 0; dist[k]; k++)
		printf("\tdist after:%f\n", *(dist[k]));
	ft_free_array((void **)index);
	ft_free_array((void **)dist);
}

static double	**sprites_dist(t_data *data)
{
	double	**arr;
	int		i;
	double	pos_x;
	double	pos_y;

	i = -1;
	pos_x = data->player.position[0];
	pos_y = data->player.position[1];
	arr = (double **)ft_calloc(data->map.sprite_nb + 1, sizeof(double *));
	if (!arr)
		return (err_alloc());
	while (++i < (int)data->map.sprite_nb)
	{
		arr[i] = (double *)ft_calloc(1, sizeof(double));
		if (!arr[i])
		{
			ft_free_array((void **)arr);
			return (err_alloc());
		}
		*(arr[i]) = ((pos_x - data->arr_s[i]->pos_x)
				* (pos_x - data->arr_s[i]->pos_x)
				+ (pos_y - data->arr_s[i]->pos_y)
				* (pos_y - data->arr_s[i]->pos_y));
	}
	return (arr);
}

size_t	**sort_sprites(t_data *data)
{
	size_t	**sprites;
	double	**arr_dist;
	int		i;

	i = -1;
	sprites = (size_t **)ft_calloc(data->map.sprite_nb + 1, sizeof(size_t *));
	if (!sprites)
		return (err_alloc());
	while (++i < (int)data->map.sprite_nb)
	{
		sprites[i] = (size_t *)ft_calloc(1, sizeof(size_t));
		if (!sprites[i])
			ft_free_array((void **)sprites);
		if (!sprites[i])
			return (err_alloc());
		*(sprites[i]) = (size_t)i;
	}
	arr_dist = sprites_dist(data);
	if (!arr_dist)
		ft_free_array((void **)sprites);
	if (!arr_dist)
		return (err_alloc());
	order_sprite(data->arr_s, sprites, arr_dist);
	return (sprites);
}
