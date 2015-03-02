/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:41:34 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/22 18:13:21 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	register int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i - 1] || !i)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		++i;
	}
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	register int	i;

	if (!s)
		return (NULL);
	i = (int)ft_strlen(s);
	while (s[i] || i > 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		--i;
	}
	return (NULL);
}
