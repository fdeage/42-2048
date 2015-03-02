/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 12:58:00 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/01 23:04:29 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <_types/_uint8_t.h>
#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;
	uint8_t	*str1;
	uint8_t	*str2;
	uint8_t	test;

	if (!n || !s1 || !s2)
		return (NULL);
	i = 0;
	str1 = (uint8_t*)s1;
	str2 = (uint8_t*)s2;
	test = (uint8_t)c;
	while (i < n)
	{
		*(str1 + i) = *(str2 + i);
		if (*(str2 + i) == test)
			return (str1 + i + 1);
		++i;
	}
	return (NULL);
}

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	uint8_t	*s3;
	uint8_t	*s4;

	if (!s1 || !s2)
		return (s1);
	s3 = (uint8_t *)s1;
	s4 = (uint8_t *)s2;
	while (n--)
		*s3++ = *s4++;
	return (s1);
}
