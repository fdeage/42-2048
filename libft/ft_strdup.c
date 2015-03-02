/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 13:00:39 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/13 17:41:32 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Mem leaks!
** strdup is an OpenBSD implementation
*/

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	size;

	size = ft_strlen(s1) + 1;
	if (!(s2 = (char *)malloc((size) * sizeof(char))))
		return (NULL);
	(void)ft_memcpy(s2, s1, size);
	return (s2);
}
