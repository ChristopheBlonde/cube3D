/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:20:59 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/16 12:35:12 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"
# include "def_color.h"
# include <errno.h>
# include <stdio.h>

# define ERR "Error\n"
# define FAILALLOC "Allocation fail\n"
# define FAILOPEN "Cannot open file\n"
# define FAILCLOSE "Fail close file\n"
# define ERREXTENTION ": Bad exention file\n"
# define ERRARG "Unknow argument in file\n"
# define ERRDNO "Duplicate file for north texture\n"
# define ERRDSO "Duplicate file for south texture\n"
# define ERRDWE "Duplicate file for west texture\n"
# define ERRDEA "Duplicate file for east texture\n"

void	*err_alloc(void);
size_t	err_arg(void);
size_t	err_open(char *s);
size_t	err_duplicate(size_t n);

#endif
