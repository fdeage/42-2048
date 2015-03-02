/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:55:12 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/22 12:31:29 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** conversion in unsigned char so that `\200' is greater than `\0' (cf. man)
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	register size_t	i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (us1[i] && us1[i] == us2[i])
		++i;
	return (us1[i] - us2[i]);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	register size_t	i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	if (!n)
		return (0);
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (us1[i] && us1[i] == us2[i] && i < n - 1)
		++i;
	return (us1[i] - us2[i]);
}
