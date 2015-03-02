/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 16:22:33 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/28 13:06:49 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_itoatab() takes at most a tab[12]
*/

static void	ft_put_string_nbr(int nbr, char *dest)
{
	if (nbr >= 0)
	{
		if (nbr < 10)
		{
			while (*dest)
				++dest;
			*dest = (char)nbr + '0';
		}
		else
		{
			ft_put_string_nbr(nbr / 10, dest);
			ft_put_string_nbr(nbr % 10, dest);
		}
	}
	else
	{
		dest[0] = '-';
		ft_put_string_nbr(-nbr, dest);
	}
}

char		*ft_itoa(int nbr)
{
	char	*str;

	if (!(str = (char*)ft_memalloc(sizeof(char) * 12)))
		return (NULL);
	if (nbr == -2147483648)
	{
		ft_put_string_nbr(nbr / 10, str);
		str[10] = '8';
	}
	else
		ft_put_string_nbr(nbr, str);
	return (str);
}

char		*ft_itoatab(int nbr, char *tab)
{
	ft_bzero(tab, 12);
	if (nbr == -2147483648)
	{
		ft_put_string_nbr(nbr / 10, tab);
		(tab)[10] = '8';
	}
	else
		ft_put_string_nbr(nbr, tab);
	return (tab);
}
