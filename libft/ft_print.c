/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 21:36:57 by fdeage            #+#    #+#             */
/*   Updated: 2014/05/13 15:11:13 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** puttab prints all the strings contained in a char**, followed by a "\n"
*/

void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}

void	ft_putstr(char const *s)
{
	ft_putstr_fd(s, 1);
}

void	ft_putendl(char const *s)
{
	ft_putendl_fd(s, 1);
}

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
}

void	ft_puttab(char const **ss)
{
	ft_puttab_fd(ss, 1);
}
