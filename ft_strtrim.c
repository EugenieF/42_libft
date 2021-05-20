/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efrancon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:31:07 by efrancon          #+#    #+#             */
/*   Updated: 2021/05/20 14:31:08 by efrancon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*dest;

	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (end && is_set(s1[end], set))
		end--;
	while (s1[start] && is_set(s1[start], set))
		start++;
	if (s1[start] == '\0')
	{
		dest = malloc(sizeof(char));
		dest[0] = '\0';
		return (dest);
	}
	dest = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!dest)
		return (NULL);
	while (start <= end)
		dest[i++] = s1[start++];
	dest[i] = '\0';
	return (dest);
}
