/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:51:44 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/26 22:38:08 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strlcat() function appends the NUL-terminated string src to the end of
** dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-terminating
** the result.
*/
char	*ft_strcat(char *dst, const char *src)
{
	return (ft_strncat(dst, src, 2147483647));
}

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	register size_t	i;
	register size_t	j;

	i = 0;
	while (dst[i])
		++i;
	j = 0;
	while (src[j] && j < n)
	{
		dst[i + j] = src[j];
		++j;
	}
	dst[i + j] = '\0';
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			len_dst;
	size_t			len_src;
	register size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (size < len_dst)
		return (len_src + size);
	while (src[i] && i + len_dst < size - 1)
	{
		dst[len_dst + i] = src[i];
		++i;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
