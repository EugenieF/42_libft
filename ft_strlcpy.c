/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efrancon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:29:49 by efrancon          #+#    #+#             */
/*   Updated: 2021/05/20 14:29:50 by efrancon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = 0;
	while (src[src_size])
		src_size++;
	while (src[i] && i + 1 < dst_size)
	{
		dest[i] = src[i];
		i++;
	}
	if (dst_size > 0)
		dest[i] = '\0';
	return (src_size);
}
