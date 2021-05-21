/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efrancon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:24:06 by efrancon          #+#    #+#             */
/*   Updated: 2021/05/21 19:03:59 by efrancon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*begin_list;

	begin_list = NULL;
	while (lst)
	{
		new_list = ft_lstnew((*f)(lst->content));
		if (!new_list)
		{
			ft_lstclear(&begin_list, del);
			return (NULL);
		}
		ft_lstadd_back(&begin_list, new_list);
		lst = lst->next;
	}
	return (begin_list);
}
