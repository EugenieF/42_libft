/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EugenieFrancon <EugenieFrancon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:29:29 by efrancon          #+#    #+#             */
/*   Updated: 2021/07/03 11:17:42 by EugenieFran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)ft_calloc(1, sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (*s1)
		dest[i++] = *s1++;
	while (*s2)
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}
