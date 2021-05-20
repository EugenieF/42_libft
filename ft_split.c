/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efrancon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:28:58 by efrancon          #+#    #+#             */
/*   Updated: 2021/05/20 14:29:00 by efrancon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

void	ft_get_memory(char const *s, char c, char **strs, int i)
{
	int	j;

	j = 0;
	while (s[j] && s[j] != c)
		j++;
	strs[i] = (char *)malloc(sizeof(char) * (j + 1));
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	**strs;

	i = 0;
	len = nb_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (len + 1));
	if (!strs)
		return (NULL);
	while (i < len)
	{
		while (*s && *s == c)
			s++;
		ft_get_memory(s, c, strs, i);
		if (!strs[i])
			return (NULL);
		j = 0;
		while (*s && *s != c)
			strs[i][j++] = *s++;
		strs[i++][j] = '\0';
	}
	strs[i] = NULL;
	return (strs);
}
