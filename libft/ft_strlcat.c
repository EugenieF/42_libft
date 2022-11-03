/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efrancon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:29:37 by efrancon          #+#    #+#             */
/*   Updated: 2021/05/20 14:29:39 by efrancon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dest_len;

	i = 0;
	dest_len = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	while (dest[dest_len])
		dest_len++;
	if (dst_size == 0)
		return (src_len);
	j = dest_len;
	while (src[i] && i + 1 + dest_len < dst_size)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	if (dst_size < dest_len + 1)
		return (src_len + dst_size);
	return (src_len + dest_len);
}
