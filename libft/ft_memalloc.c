/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 18:54:26 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/01 23:04:07 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** realloc(), like calloc(), allocates, sets the memory to 0, and returns
*/

void	*ft_calloc(size_t size)
{
	void	*new;

	if (!(new = malloc(size)))
		return (NULL);
	return (ft_memset(new, 0, size));
}

void	*ft_memalloc(size_t size)
{
	return (ft_calloc(size));
}
