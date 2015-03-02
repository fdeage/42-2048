/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 13:17:31 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/27 14:00:26 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	post_dot(const char *s, int i)
{
	if (s[i] == '.')
	{
		++i;
		if (!s[i])
			return (0);
		while (s[i] && !ft_isspace(s[i]))
		{
			if (!ft_isdigit(s[i]) && !ft_isspace(s[i]))
				return (0);
			++i;
		}
	}
	while (s[i])
	{
		if (!ft_isspace(s[i]))
			return (0);
		++i;
	}
	return (1);
}

int			ft_isnumeric(const char *s)
{
	register int	i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		++i;
	if (s[i] == '-' || s[i] == '+')
		++i;
	while (s[i] && !ft_isspace(s[i]) && s[i] != '.')
	{
		if (!ft_isdigit(s[i]) && !ft_isspace(s[i]))
			return (0);
		++i;
	}
	return (post_dot(s, i));
}

int			ft_aredigits(const char *s)
{
	if (*s == '-' || *s == '+')
		++s;
	while (*s)
	{
		if (!ft_isdigit(*s++))
			return (0);
	}
	return (1);
}
