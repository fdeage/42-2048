/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 18:13:26 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/05 12:05:31 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	return (ft_strnstr(s1, s2, 2147483647));
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	register size_t	i;

	if (!(*s2))
		return ((char *)s1);
	i = 0;
	while (s1[i] && n)
	{
		i = 0;
		while (s1[i] == s2[i] && (int)(n - i) > 0)
		{
			++i;
			if (!s2[i])
				return ((char *)s1);
		}
		++s1;
		--n;
	}
	return (NULL);
}
