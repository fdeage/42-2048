/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:07:32 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/13 16:58:44 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Lexicographic comparison until n or \O is found. Returns 0 if equal,
** 1 if different
*/
int	ft_strequ(char const *s1, char const *s2)
{
	register size_t	i;

	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2 || (ft_strlen(s1) != ft_strlen(s2)))
		return (0);
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}
	return (1);
}

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	register size_t	i;

	if (n == 0)
		return (1);
	if (!s1 || !s2 || (ft_strlen(s1) != ft_strlen(s2)))
		return (0);
	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}
	return (1);
}
