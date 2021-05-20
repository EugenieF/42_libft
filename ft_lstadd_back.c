/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efrancon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:23:11 by efrancon          #+#    #+#             */
/*   Updated: 2021/05/20 14:23:13 by efrancon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!*alst)
		(*alst) = new;
	else
	{
		if (!(*alst)->next)
			(*alst)->next = new;
		else
			ft_lstadd_back(&(*alst)->next, new);
	}
}
