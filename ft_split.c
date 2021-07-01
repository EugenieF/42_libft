/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EugenieFrancon <EugenieFrancon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:28:58 by efrancon          #+#    #+#             */
/*   Updated: 2021/07/01 16:34:25 by EugenieFran      ###   ########.fr       */
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

static int	get_memory_string(char const *s, char c, char **strs, int i)
{
	int	j;
	int	size;

	j = 0;
	size = 0;
	while (s[j] && s[j] != c)
		j++;
	strs[i] = (char *)malloc(sizeof(char) * (j + 1));
	if (!strs[i])
	{
		while (size < i)
			free(strs[size++]);
		free(strs);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	**strs;

	if (!s)
		return (NULL);
	i = 0;
	len = nb_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (len + 1));
	if (!strs)
		return (NULL);
	while (i < len)
	{
		while (*s && *s == c)
			s++;
		if (!get_memory_string(s, c, strs, i))
			return (NULL);
		j = 0;
		while (*s && *s != c)
			strs[i][j++] = *s++;
		strs[i++][j] = '\0';
	}
	strs[i] = NULL;
	return (strs);
}
