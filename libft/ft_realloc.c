/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 13:42:01 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/13 17:43:05 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Allocates a memory which size is the power of 2 right above the number asked
** and frees the former memory allocated
** The getpow2 gives: 45->64, 64->64, 65->128
*/

static size_t	get_pow2(uint64_t nb)
{
	size_t	i;

	i = 1;
	while (i < nb)
		i <<= 1;
	return (i);
}

void			*ft_realloc(void *ptr, size_t size)
{
	void	*tmp;

	size = get_pow2(size);
	if (!ptr)
		return (ft_memalloc(size));
	tmp = ptr;
	if (!(ptr = malloc(size)))
		return (NULL);
	ft_memcpy(ptr, tmp, size);
	free(tmp);
	return (ptr);
}
