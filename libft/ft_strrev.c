/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 21:45:25 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/21 15:32:19 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** K&R implementation
*/

char	*ft_strrev(char *s)
{
	int					len;
	char				c;
	register int		i;
	register int		j;

	len = (int)ft_strlen(s);
	i = 0;
	j = len - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		++i;
		--j;
	}
	return (s);
}
