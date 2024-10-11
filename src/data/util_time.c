/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:50:31 by cblonde           #+#    #+#             */
/*   Updated: 2024/10/10 13:16:04 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

uint64_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putendl_fd("\033[0;31Error: fail get time", 2);
	return (time.tv_sec * 1000LL + time.tv_usec / 1000);
}

uint64_t	time_past(t_data *data)
{
	if (data->start_time == 0)
		data->start_time = get_time();
	return (get_time() - data->start_time);
}

bool	update(t_data *data)
{
	if (get_time() - data->last_update < (uint64_t)(1000 / data->fps))
		return (false);
	data->last_update = get_time();
	return (true);
}
