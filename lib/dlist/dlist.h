/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:35:44 by cblonde           #+#    #+#             */
/*   Updated: 2024/01/22 11:20:45 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H
# include <stdlib.h>

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*previous;
}	t_dlist;

t_dlist	*ft_dlstnew(void *content);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);
int		ft_dlstsize(t_dlist *lst);
void	ft_dlstdelone(t_dlist *lst, void (*del)(void *));
void	ft_dlstclear(t_dlist **lst, void (*del)(void *));
void	ft_dlstiter(t_dlist *lst, void (*f)(void *));
t_dlist	*ft_dlstmap(t_dlist *lst, void (*f)(void *), void (*del)(void *));
t_dlist	*ft_dlstget(t_dlist *lst, int index);
t_dlist	*ft_dlstlast(t_dlist *lst);
int		ft_dlstget_index(t_dlist *lst, int *elem);

#endif
