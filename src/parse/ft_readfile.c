/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:42:30 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/12 09:35:38 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	*ft_err_readfile(int n, int fd, char *str, char *tmp)
{
	ft_putstr_fd(LRED, 2);
	ft_putstr_fd(ERR, 2);
	if (fd >= 0)
		close(fd);
	if (str)
		free(str);
	if (tmp)
		free(tmp);
	if (n == 0)
	{
		ft_putstr_fd(DRED, 2);
		ft_putstr_fd(FAILALLOC, 2);
	}
	if (n == 1)
	{
		ft_putstr_fd(YELLOW, 2);
		ft_putstr_fd(FAILOPEN, 2);
	}
	if (n == 2)
	{
		ft_putstr_fd(BLUE, 2);
		ft_putstr_fd(FAILCLOSE, 2);
	}
	ft_putstr_fd(RESET, 2);
	return (NULL);
}

char	*ft_readfile(char *file)
{
	char	*str;
	char	*tmp;
	int		fd;

	tmp = NULL;
	fd = -1;
	str = ft_calloc(1, sizeof(char));
	if (!str)
		return (ft_err_readfile(0, fd, str, tmp));
	str[0] = '\0';
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_err_readfile(1, fd, str, tmp));
	tmp = ft_get_next_line(fd);
	while (tmp)
	{
		str = ft_strfjoin(str, tmp, 3);
		if (!str)
			return (ft_err_readfile(0, fd, str, tmp));
		tmp = ft_get_next_line(fd);
	}
	if (close(fd) == -1)
		return (ft_err_readfile(3, fd, str, NULL));
	return (str);
}
