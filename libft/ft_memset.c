/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 12:57:51 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/16 16:01:01 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <_types/_uint8_t.h>

void	*ft_memset(void *s1, int c, size_t n)
{
	register uint8_t	*s2;

	s2 = (uint8_t *)s1;
	while (n--)
		*s2++ = (uint8_t)c;
	return (s1);
}

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
}
