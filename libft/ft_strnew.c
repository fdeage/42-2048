/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 19:29:32 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/13 16:48:40 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

char	*ft_strnew(size_t size)
{
	char			*new;
	register size_t	i;

	if (size >= SIZE_MAX)
		size = SIZE_MAX - 1;
	if (!(new = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i <= size)
		new[i++] = '\0';
	return (new);
}
