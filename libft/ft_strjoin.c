/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 12:56:23 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/13 17:41:48 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** beware of memory leaks with strjoin!
** strjoin doesn't free the old dst nor src
*/
char	*ft_strjoin(char const *dst, char const *src)
{
	char			*new;
	size_t			len_dst;
	size_t			len_src;
	register size_t	i;

	if (!src)
		return (NULL);
	len_dst = (dst ? ft_strlen(dst) : 0);
	len_src = ft_strlen(src);
	if (!(new = (char *)malloc((len_dst + len_src + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len_dst)
	{
		new[i] = dst[i];
		++i;
	}
	while (i < len_dst + len_src)
	{
		new[i] = src[i - len_dst];
		++i;
	}
	new[i] = '\0';
	return (new);
}
