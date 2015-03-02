/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 13:00:30 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/23 12:44:08 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *s1, const char *s2, size_t len)
{
	register size_t	i;

	if (!s1)
		return (s1);
	i = 0;
	while (s2[i] && i < len)
	{
		s1[i] = s2[i];
		++i;
	}
	while (i < len)
		s1[i++] = '\0';
	return (s1);
}

char	*ft_strcpy(char *s1, const char *s2)
{
	register size_t	i;

	if (!s1)
		return (s1);
	i = 0;
	while (*s2)
		s1[i++] = *s2++;
	s1[i] = '\0';
	return (s1);
}
