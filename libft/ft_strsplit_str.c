/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 22:22:59 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/16 12:28:20 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Mem leaks!
*/

static int	cmp(char c, char const *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		++str;
	}
	return (0);
}

static int	n(char const *s1, char const *s2)
{
	int	word;

	word = 0;
	while (*s1)
	{
		if (cmp(*s1, s2) != 1)
			++word;
		while (cmp(*s1, s2) != 1 && *s1 != 0)
			++s1;
		while (cmp(*s1, s2) == 1)
			++s1;
	}
	return (word);
}

char		**ft_strsplit_str(char const *s1, char const *s2)
{
	char	**tab;
	int		start;
	int		word;
	int		i;

	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (n(s1, s2) + 1))))
		return (NULL);
	word = -1;
	i = 0;
	while (s1[i])
	{
		if (cmp(s1[i], s2) != 1)
			word++;
		start = i;
		while (cmp(s1[i], s2) != 1 && s1[i])
			i++;
		if (word >= 0)
			tab[word] = ft_strsub(s1, (unsigned)start, (unsigned)(i - start));
		while (cmp(s1[i], s2) == 1)
			i++;
	}
	tab[word + 1] = NULL;
	return (tab);
}
