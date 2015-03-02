/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 20:06:13 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/23 12:46:42 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Mem leaks!
*/

static int	n(char const *str, char c)
{
	register size_t	i;
	register size_t	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != c)
			++word;
		while (str[i] && str[i] != c)
			++i;
		while (str[i] && str[i] == c)
			++i;
	}
	return (word);
}

char		**ft_strsplit(char const *str, char c)
{
	char			**tab;
	int				st;
	int				word;
	register size_t	i;

	if (!str || !(tab = (char **)ft_memalloc(sizeof(char *)
				* (size_t)(n(str, c) + 1))))
		return (NULL);
	word = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			++word;
		st = i;
		while (str[i] && str[i] != c)
			++i;
		if (word >= 0)
			tab[word] = ft_strsub(str, (unsigned int)st, (size_t)(i - st));
		while (str[i] == c)
			++i;
	}
	tab[word + 1] = NULL;
	return (tab);
}
