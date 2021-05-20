/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efrancon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:24:06 by efrancon          #+#    #+#             */
/*   Updated: 2021/05/20 14:24:07 by efrancon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (NULL);
	tmp = new;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = ft_lstnew((*f)(lst->content));
		if (!(tmp->next))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (new);
}
