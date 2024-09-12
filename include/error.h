/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:20:59 by cblonde           #+#    #+#             */
/*   Updated: 2024/09/12 15:56:03 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"
# include "def_color.h"

# define ERR "Error\n"
# define FAILALLOC "Allocation fail\n"
# define FAILOPEN "Cannot open file\n"
# define FAILCLOSE "Fail close file\n"
# define ERREXTENTION ": Bad exention file\n"

void	*err_alloc(void);

#endif
